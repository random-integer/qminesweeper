#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tile.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void explode();

private:
    Ui::MainWindow *ui;
    void lose();
    void win();
    Tile *tiles[10][10];
private slots:
    void dig(int row, int col);
    void reveal(int row, int col);  // called when a neighboring tile of count 0 is dug()
};
#endif // MAINWINDOW_H
