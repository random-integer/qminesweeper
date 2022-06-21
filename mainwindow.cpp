#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tile.h"
#include <QTextStream>
#include <QMessageBox>
#include <vector>
#include <random>
#include <iostream>

#define MINECOUNT 16
// #define DEBUG
// #define CHEAT
// FASTDIG switch is in mainwindow.h

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    markedMineCount(0),
    markedSafeTileCount(0),
    dugCount(0) {
    ui->setupUi(this);
    // tiles[row][column]
    /*  // doesn't seem to work quite reliably
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tiles[i][j] = static_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i, j)->widget());
            // tiles[i][j] = tileij
        }
    }
    */

    if (true) {    // so far, this seems to be the most robust way I've found
        tiles[0][0] = ui->tile00;
        tiles[0][1] = ui->tile01;
        tiles[0][2] = ui->tile02;
        tiles[0][3] = ui->tile03;
        tiles[0][4] = ui->tile04;
        tiles[0][5] = ui->tile05;
        tiles[0][6] = ui->tile06;
        tiles[0][7] = ui->tile07;
        tiles[0][8] = ui->tile08;
        tiles[0][9] = ui->tile09;
        tiles[1][0] = ui->tile10;
        tiles[1][1] = ui->tile11;
        tiles[1][2] = ui->tile12;
        tiles[1][3] = ui->tile13;
        tiles[1][4] = ui->tile14;
        tiles[1][5] = ui->tile15;
        tiles[1][6] = ui->tile16;
        tiles[1][7] = ui->tile17;
        tiles[1][8] = ui->tile18;
        tiles[1][9] = ui->tile19;
        tiles[2][0] = ui->tile20;
        tiles[2][1] = ui->tile21;
        tiles[2][2] = ui->tile22;
        tiles[2][3] = ui->tile23;
        tiles[2][4] = ui->tile24;
        tiles[2][5] = ui->tile25;
        tiles[2][6] = ui->tile26;
        tiles[2][7] = ui->tile27;
        tiles[2][8] = ui->tile28;
        tiles[2][9] = ui->tile29;
        tiles[3][0] = ui->tile30;
        tiles[3][1] = ui->tile31;
        tiles[3][2] = ui->tile32;
        tiles[3][3] = ui->tile33;
        tiles[3][4] = ui->tile34;
        tiles[3][5] = ui->tile35;
        tiles[3][6] = ui->tile36;
        tiles[3][7] = ui->tile37;
        tiles[3][8] = ui->tile38;
        tiles[3][9] = ui->tile39;
        tiles[4][0] = ui->tile40;
        tiles[4][1] = ui->tile41;
        tiles[4][2] = ui->tile42;
        tiles[4][3] = ui->tile43;
        tiles[4][4] = ui->tile44;
        tiles[4][5] = ui->tile45;
        tiles[4][6] = ui->tile46;
        tiles[4][7] = ui->tile47;
        tiles[4][8] = ui->tile48;
        tiles[4][9] = ui->tile49;
        tiles[5][0] = ui->tile50;
        tiles[5][1] = ui->tile51;
        tiles[5][2] = ui->tile52;
        tiles[5][3] = ui->tile53;
        tiles[5][4] = ui->tile54;
        tiles[5][5] = ui->tile55;
        tiles[5][6] = ui->tile56;
        tiles[5][7] = ui->tile57;
        tiles[5][8] = ui->tile58;
        tiles[5][9] = ui->tile59;
        tiles[6][0] = ui->tile60;
        tiles[6][1] = ui->tile61;
        tiles[6][2] = ui->tile62;
        tiles[6][3] = ui->tile63;
        tiles[6][4] = ui->tile64;
        tiles[6][5] = ui->tile65;
        tiles[6][6] = ui->tile66;
        tiles[6][7] = ui->tile67;
        tiles[6][8] = ui->tile68;
        tiles[6][9] = ui->tile69;
        tiles[7][0] = ui->tile70;
        tiles[7][1] = ui->tile71;
        tiles[7][2] = ui->tile72;
        tiles[7][3] = ui->tile73;
        tiles[7][4] = ui->tile74;
        tiles[7][5] = ui->tile75;
        tiles[7][6] = ui->tile76;
        tiles[7][7] = ui->tile77;
        tiles[7][8] = ui->tile78;
        tiles[7][9] = ui->tile79;
        tiles[8][0] = ui->tile80;
        tiles[8][1] = ui->tile81;
        tiles[8][2] = ui->tile82;
        tiles[8][3] = ui->tile83;
        tiles[8][4] = ui->tile84;
        tiles[8][5] = ui->tile85;
        tiles[8][6] = ui->tile86;
        tiles[8][7] = ui->tile87;
        tiles[8][8] = ui->tile88;
        tiles[8][9] = ui->tile89;
        tiles[9][0] = ui->tile90;
        tiles[9][1] = ui->tile91;
        tiles[9][2] = ui->tile92;
        tiles[9][3] = ui->tile93;
        tiles[9][4] = ui->tile94;
        tiles[9][5] = ui->tile95;
        tiles[9][6] = ui->tile96;
        tiles[9][7] = ui->tile97;
        tiles[9][8] = ui->tile98;
        tiles[9][9] = ui->tile99;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // tiles[i][j]->setText(QString("%1").arg(10 * i + j));
            connect(tiles[i][j], &Tile::clicked, this, [=]() { this->dig(i, j); });
            connect(tiles[i][j], &Tile::rightClicked, this, [=]() { this->mark(i, j); });
#ifdef FASTDIG
            connect(tiles[i][j], &Tile::middleClicked, this, [=]() { this->fastDig(i, j); });
#endif // FASTDIG
            connect(this, &MainWindow::explode, tiles[i][j], &Tile::detonate);
            tiles[i][j]->row = i;
            tiles[i][j]->col = j;
        }
    }
    // the numbers from 0 to 99
    notMines = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::dig(int row, int col) {
    if (dugCount == 0) generateMines(row, col);
    if (tiles[row][col]->marked == 0) {
        if (tiles[row][col]->mine) {
            lose();
            QApplication::quit();
        } else {
            tiles[row][col]->setEnabled(false);
            dugCount++;
#ifdef DEBUG
            std::cout << "dugCount: " << dugCount-1 << "->" << dugCount << '\n';
#endif // DEBUG
            int count = getCount(row, col);
            if (count == 0) {
                reveal(row, col+1);
                reveal(row-1, col);      // don't worry about the row±1 or col±1 going out of range,
                reveal(row, col-1);        // reveal() would handle that
                reveal(row+1, col);
            } else {
                tiles[row][col]->setText(QString("%1").arg(count));
                tiles[row][col]->setStyleSheet(getColorOf(count));
            }
            checkIfWon();
        }
    }
}


void MainWindow::reveal(int row, int col) {
    // | out     of          range                |    marked                    |   is mine              |       ! is dug               |
    if (row < 0 || row > 9 || col < 0 || col > 9 || tiles[row][col]->marked > 0 || tiles[row][col]->mine || !tiles[row][col]->isEnabled()) {
        return;
    } else if (getCount(row, col) == 0) {
        dugCount++;
#ifdef DEBUG
        std::cout << "dugCount: " << dugCount-1 << "->" << dugCount << '\n';
#endif // DEBUG
        tiles[row][col]->setEnabled(false);
        reveal(row, col+1);
        reveal(row-1, col);
        reveal(row, col-1);
        reveal(row+1, col);
    } else {
        dugCount++;
#ifdef DEBUG
            std::cout << "dugCount: " << dugCount-1 << "->" << dugCount << '\n';
#endif // DEBUG
        tiles[row][col]->setEnabled(false);
        tiles[row][col]->setText(QString("%1").arg(getCount(row, col)));
        tiles[row][col]->setStyleSheet(getColorOf(getCount(row, col)));
    }
    checkIfWon();
}

void MainWindow::mark(int row, int col) {
    if (dugCount == 0) {
        QMessageBox msgBox;
        msgBox.setText("You can't put down a flag on your first move");
        msgBox.setInformativeText("Silly you");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        return;
    }
    switch (tiles[row][col]->marked) {
    case 0:
        tiles[row][col]->marked = 1;
        tiles[row][col]->setText("⚑");
        if (tiles[row][col]->mine) {
            markedMineCount++;
#ifdef DEBUG
            std::cout << "markedMineCount: " << markedMineCount-1 << "->" << markedMineCount << '\n';
#endif // DEBUG
        } else {
            markedSafeTileCount++;
#ifdef DEBUG
            std::cout << "markedSafeTileCount: " << markedSafeTileCount-1 << "->" << markedSafeTileCount << '\n';
#endif // DEBUG
        }
        break;
    case 1:
        tiles[row][col]->marked = 2;
        tiles[row][col]->setText("?");
        if (tiles[row][col]->mine) {
            markedMineCount--;
#ifdef DEBUG
            std::cout << "markedMineCount: " << markedMineCount+1 << "->" << markedMineCount << '\n';
#endif // DEBUG
        } else {
            markedSafeTileCount--;
#ifdef DEBUG
            std::cout << "markedSafeTileCount: " << markedSafeTileCount+1 << "->" << markedSafeTileCount << '\n';
#endif // DEBUG
        }
        break;
    case 2:
        tiles[row][col]->marked = 0;
        tiles[row][col]->setText("");
    }
    checkIfWon();
}

#ifdef FASTDIG
void MainWindow::fastDig(int row, int col) {
    int flagged = isFlagged(row, col+1) + isFlagged(row-1, col+1) + isFlagged(row-1, col) + isFlagged(row-1, col-1) + isFlagged(row, col-1)
            + isFlagged(row+1, col-1) + isFlagged(row+1, col) + isFlagged(row+1, col+1);
    if (dugCount == 0) {
        QMessageBox msgBox;
        msgBox.setText("You can't middle click on your first move");
        msgBox.setInformativeText("Silly you");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
    } else if (getCount(row, col) == flagged && !tiles[row][col]->mine && !tiles[row][col]->isEnabled()) {
        dig(row, col+1);
        dig(row-1, col+1);
        dig(row-1, col);
        dig(row-1, col-1);
        dig(row, col-1);
        dig(row+1, col-1);
        dig(row+1, col);
        dig(row+1, col+1);
    }

}
#endif // FASTDIG

int MainWindow::getCount(int row, int col) {
    return isMine(row, col+1) + isMine(row-1, col+1) + isMine(row-1, col) + isMine(row-1, col-1) + isMine(row, col-1) + isMine(row+1, col-1)
            + isMine(row+1, col) + isMine(row+1, col+1);
}

void MainWindow::lose() {
    emit explode();
    QMessageBox msgBox;
    msgBox.setText("You lost!");
    msgBox.setInformativeText("Sucks to be you");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

void MainWindow::win() {
    QMessageBox msgBox;
    msgBox.setText("You win! Congrats!");
    msgBox.setInformativeText("Nice job!");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

void MainWindow::checkIfWon() {
    if (dugCount == 100 - MINECOUNT || (markedMineCount == MINECOUNT && markedSafeTileCount == 0)) {
        win();
        QApplication::quit();
    }
}

QString MainWindow::getColorOf(int count) {
    switch (count) {
    case 1:
        return "color: rgb(0, 0, 253)";
        break;
    case 2:
        return "color: rgb(1, 126, 0)";
        break;;
    case 3:
        return "color: rgb(254, 0, 0)";
        break;
    case 4:
        return "color: rgb(1, 1, 128)";
        break;
    case 5:
        return "color: rgb(131, 0, 3)";
        break;
    case 6:
        return "color: rgb(0, 128, 128)";
        break;
    case 7:
        return "color: rgb(0, 0, 0)";
        break;
    case 8:
        return "color: rgb(128, 128, 128)";
        break;
    default:    // shouldn't happen but oh well i'll leave it here
        return "color: rgb(200, 20, 200)";
    }
}

void MainWindow::removeFromNotMines(int row, int col) {
    if (row < 0 || row > 9 || col < 0 || col > 9) {
        return;
    } else {
        tiles[row][col]->mine = false;
        for (int i = 0; i < (int) notMines.size(); i++) {
            if (notMines.at(i) == row * 10 + col) {
                notMines.erase(notMines.begin() + i);
                break;
            }
        }
    }
}

void MainWindow::generateMines(int row, int col) {
    removeFromNotMines(row, col);
    removeFromNotMines(row+1, col+1);
    removeFromNotMines(row+1, col-1);
    removeFromNotMines(row+1, col);
    removeFromNotMines(row-1, col+1);
    removeFromNotMines(row-1, col-1);
    removeFromNotMines(row-1, col);
    removeFromNotMines(row, col+1);
    removeFromNotMines(row, col-1);

    int a, b;
    for (int i = 0; i < MINECOUNT; i++) {    // regen lost mines
        b = rand() % (91 - i);
        a = notMines.at(b);
        notMines.erase(notMines.begin() + b);
        tiles[a/10][a%10]->mine = true;
#ifdef CHEAT
        tiles[a/10][a%10]->setStyleSheet("background-color: rgb(80, 80, 80)");
#endif // CHEAT
    }
}

bool MainWindow::isMine(int row, int col) {
    if (row < 0 || row > 9 || col < 0 || col > 9) {
        return false;
    } else {
        return tiles[row][col]->mine;
    }
}

bool MainWindow::isFlagged(int row, int col) {
    if (row < 0 || row > 9 || col < 0 || col > 9) {
        return false;
    } else {
        return tiles[row][col]->marked;   // implicit conversion! both 1 and 2 become true, while 0 becomes false
    }
}
