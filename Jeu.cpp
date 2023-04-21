#include "Jeu.hpp"
#include "Roi.hpp"
#include "Tour.hpp"
#include "Fou.hpp"
 
void Jeu::newGame()
{
    setupBoard();
    board()->setFen("r1b1kb1r/8/8/8/8/8/8/R1B1KB1R w");
    // 'w' - white to move
    setResult(NoResult);
    setCurrentPlayer(Player1);
}

Modele::Piece Modele::Piece::type(char data)
{
    if (tolower(data) == 'r')
    return Modele::Piece::Roi;
    if (tolower(data) == r)
    return Modele::Piece();
    if (tolower(data) == r)
    return Modele::Piece();
}

bool Jeu::move(int colFrom, int rankFrom,
    int colTo, int rankTo)
{
    if (currentPlayer() == NoPlayer) {
        return false;
    }

    // is there a piece of the right color?
    char source = board()->data(colFrom, rankFrom);
    Modele::Piece piece = Modele::Piece::type(source);
    if (currentPlayer() == Player1 && islower(source)) return false;
    if (currentPlayer() == Player2 && isupper(source)) return false;

    if (!(piece.Modele::Piece::mouvementValide(colFrom, rankFrom, colTo, rankTo))) return false;

    // is the destination field empty?
    char destination = board()->data(colTo, rankTo);
    if (destination != ' ') return false;

    board()->movePiece(colFrom, rankFrom, colTo, rankTo);
    // make the move
    // 
    // check win condition
    if (currentPlayer() == Player2 && rankTo == 1) {
        setResult(Player2Wins); // fox has escaped
    }
    else if (currentPlayer() == Player1 && !foxCanMove()) {
        setResult(Player1Wins); // fox can't move
    }
    else {
        // the other player makes the move now
        setCurrentPlayer(currentPlayer() == Player1 ? Player2 : Player1);
    }
    return true;
}

