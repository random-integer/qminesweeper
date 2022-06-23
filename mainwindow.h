#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tile.h"
#include <QMainWindow>
#include <vector>

// #define FASTDIG

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
    void lose();                                      // called when the user clicks on a mine
    void win();                                       // called when the user has dug all the safe tiles
    // both lose() and win() shows a dialog
    int getCount(int row, int col);                   // returns how many mines there are in the neighboring 8 tiles of tiles[row, col]
                                                      // with bounds checking
    void checkIfWon();
    QString getColorOf(int count);                    // returns a QString in the format of "color: rgb(r, g, b)" given the count of a tile
    void generateMines(int row, int col);             // called when the user makes their first move
    bool isMine(int row, int col);                    // with bounds checking
    bool isFlagged(int row, int col);                 // with bounds checking. also, a ? counts as a zero
    void removeFromCanPutMines(int row, int col);        // called by generateMines() to remove the neighboring cells of the tile dug on the first move and
                                                      // itself from canPutMines, the list of possible mine locations
    Tile *tiles[10][10];                              // a list containing the all the tiles
    int markedMineCount;                              // how many mines are flagged by the user (? doesn't count)
    int markedSafeTileCount;                          // how many safe tiles are wrongly flagged
    int dugCount;                                     // how many tiles have been dug
    std::vector<int> canPutMines;
private slots:
    void dig(int row, int col);                       // called when a tile is left-clicked
    void reveal(int row, int col);                    // called when a neighboring tile of count 0 is dug()
    void mark(int row, int col);
#ifdef FASTDIG
    void fastDig(int row, int col);  // called when a tile is middle clicked
#endif // FASTDIG
};
#endif // MAINWINDOW_H
