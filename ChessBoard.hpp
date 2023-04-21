#pragma once
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QVector>
#include <functional>

#pragma pop()

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class ChessBoard : public QObject {
	Q_OBJECT
		Q_PROPERTY(int ranks READ ranks NOTIFY ranksChanged)
		Q_PROPERTY(int columns READ columns NOTIFY columnsChanged)
public:	
	ChessBoard(int, int, QObject*);
	int ranks() const { return m_ranks; };
	int columns() const { return m_columns; };
	char data(int column, int rank) const;
	void setData(int column, int rank, char value);
	void movePiece(int fromColumn, int fromRank, int toColumn, int toRank);
	void setFen(const QString& fen);
	void verifierNbrRois();
	
public slots:

signals:
	void ranksChanged(int);
	void columnsChanged(int);
	void dataChanged(int c, int r);
	void boardReset();

protected:
	void initBoard();
	void setRanks(int newRanks);
	void setColumns(int newColumns);
	bool setDataInternal(int column, int rank, char value);


private:
	int m_ranks;
	int m_columns;
	QVector<char> m_boardData;
};
