#pragma once
#include <QObject>
#include "ChessAlgorithm.hpp"

class Jeu : public ChessAlgorithm, public Modele::Piece{
public:
    Jeu(QObject* parent = 0);
    void newGame();
    bool move(int colFrom, int rankFrom, int colTo, int rankTo);
};

namespace Modele {
    class Piece
    {
    public:
        virtual bool mouvementValide(int colFrom, int rankFrom, int colTo, int rankTo) { return 0 };
        Piece type(char data);
    };
}