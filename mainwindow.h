#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tile.h"
#include <QMainWindow>
#include <vector>

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
    int getCount(int row, int col);
    void checkIfWon();
    QString getColorOf(int count);
    void generateMines(int row, int col);
    bool isMine(int row, int col);    // with bounds checking
    void removeFromNotMines(int row, int col);
    Tile *tiles[10][10];
    int markedMineCount;
    int markedSafeTileCount;
    int dugCount;
    std::vector<int> notMines;
private slots:
    void dig(int row, int col);
    void reveal(int row, int col);  // called when a neighboring tile of count 0 is dug()
    void mark(int row, int col);
    // void fastDig(int row, int col);  // called when a tile is middle clicked
};
#endif // MAINWINDOW_H
