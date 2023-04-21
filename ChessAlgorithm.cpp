#include "ChessAlgorithm.hpp"


ChessAlgorithm::ChessAlgorithm(QObject* parent) :
    QObject(parent),
    m_result(NoResult),
    m_currentPlayer(NoPlayer)
{
}

ChessBoard* ChessAlgorithm::board() const
{
    return m_board;
}

void ChessAlgorithm::setBoard(ChessBoard* board)
{
    if (board == m_board) {
        return;
    }
    delete m_board;
    m_board = board;
    emit boardChanged(m_board);
}

void ChessAlgorithm::setupBoard()
{
    setBoard(new ChessBoard(8, 8, this));
}

void ChessAlgorithm::newGame()
{
    setupBoard();
    board()->setFen(
        "r1b1kb1r/8/8/8/8/8/8/R1B1KB1R w KQkq - 0 1"
    );
}

void ChessAlgorithm::setResult(Result value)
{
    if (result() == value) {
        return;
    }
    if (result() == NoResult) {
        m_result = value;
        emit gameOver(m_result);
    }
    else {
        m_result = value;
    }
}

void ChessAlgorithm::setCurrentPlayer(Player value)
{
    if (currentPlayer() == value) {
        return;
    }
    m_currentPlayer = value;
    emit currentPlayerChanged(m_currentPlayer);
}

bool ChessAlgorithm::move(int colFrom, int rankFrom,
    int colTo, int rankTo)
{
    Q_UNUSED(colFrom)
    Q_UNUSED(rankFrom)
    Q_UNUSED(colTo)
    Q_UNUSED(rankTo)
    return false;
}

bool ChessAlgorithm::move(const QPoint& from, const QPoint& to)
{
    return move(from.x(), from.y(), to.x(), to.y());
}