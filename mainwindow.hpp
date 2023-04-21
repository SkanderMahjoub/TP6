
#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#pragma once
#include <QObject>
#include <QMetaObject>
#include <QMainWindow>
#include <QWidget>
#include <QLayout>
#include <QSizePolicy>
#include <QSize>
#include <QApplication>
#include <QtCore>
#include "ChessView.hpp"
#include "ChessAlgorithm.hpp"
#include "Highlight.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void viewClicked(const QPoint& field);

private:
    ChessView* m_view;
    ChessAlgorithm* m_algorithm;
    QPoint m_clickPoint;
    FieldHighlight* m_selectedField;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
