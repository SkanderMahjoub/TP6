#pragma once
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QPoint>

#include "ChessBoard.hpp"
#pragma pop()
class ChessAlgorithm : public QObject
{
    Q_OBJECT
        Q_PROPERTY(Result result READ result)
        Q_PROPERTY(Player currentPlayer
            READ currentPlayer
            NOTIFY currentPlayerChanged)
public:
    enum Result { NoResult, Player1Wins, Draw, Player2Wins };
    Q_ENUM(Result)
        enum Player { NoPlayer, Player1, Player2 };
    Q_ENUM(Player)

    explicit ChessAlgorithm(QObject* parent = 0);
    ChessBoard* board() const;
    inline Result result() const {
        return m_result;
    }
    inline Player currentPlayer() const {
        return m_currentPlayer;
    }

signals:
    void boardChanged(ChessBoard*);
    void gameOver(Result);
    void currentPlayerChanged(Player);

public slots:
    virtual void newGame();
    virtual bool move(int colFrom, int rankFrom, int colTo, int rankTo);
    bool move(const QPoint& from, const QPoint& to);

protected:
    virtual void setupBoard();
    void setBoard(ChessBoard* board);
    void setResult(Result);
    void setCurrentPlayer(Player);
private:
    ChessBoard* m_board;
    Result m_result;
    Player m_currentPlayer;
};