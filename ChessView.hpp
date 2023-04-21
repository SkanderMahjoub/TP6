#pragma once
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.

#include <QObject>
#include <QWidget>
#include <QPointer>
#include <QPoint>
#include <QList>
#include <QSize>
#include <QRect>
#include <QPaintEvent>
#include <QPainter>
#include <QColor>
#include <QPalette>
#include <QMap>
#include <QIcon>
#include <QMouseEvent>

#include "ChessBoard.hpp"
#include "Highlight.hpp"
#include "Piece.hpp"
#pragma pop()

class ChessView: public QWidget
{
	Q_OBJECT
		Q_PROPERTY(QSize fieldSize 
			READ fieldSize WRITE setFieldSize 
			NOTIFY fieldSizeChanged)
public:
	ChessBoard* board() const;
	void setBoard(ChessBoard*);
	QSize fieldSize() const;
	void setFieldSize(QSize arg);
	QSize sizeHint() const;
	QRect fieldRect(int column, int rank) const;
	void paintEvent(QPaintEvent*);
//Pieces
	void setPiece(char type, const QIcon& icon);
	QIcon piece(char type) const;
	void setupView();
//Detection de clicks
	QPoint fieldAt(const QPoint& pt) const;
	void mouseReleaseEvent(QMouseEvent* event);
//Highlight
	void addHighlight(Highlight* hl);
	void removeHighlight(Highlight* hl);
	void drawHighlights(QPainter* painter);
	inline Highlight* highlight(int index) const {
		return m_highlights.at(index);
	}
	inline int highlightCount() const {
		return m_highlights.size();
	}

protected:
	virtual void drawRank(QPainter* painter, int rank);
	virtual void drawColumn(QPainter* painter, int column);
	virtual void drawField(QPainter* painter, int column, int rank);
//Pieces
	void drawPiece(QPainter* painter, int column, int rank);

signals:
	void fieldSizeChanged(QSize);
	void clicked(const QPoint&);

private:
	QPointer<ChessBoard> m_board;
	QSize m_fieldSize;
	QMap<char, QIcon> m_pieces;
	QList<Highlight*> m_highlights;
};

