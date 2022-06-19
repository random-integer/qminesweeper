#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Tile *tiles[10][10];
    // tiles[row][column]
    /*  // doesn't seem to work quite reliably
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tiles[i][j] = static_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i, j)->widget());
            // tiles[i][j] = tileij
        }
    }
    */

    if (true) {
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
            // connect(tiles[i][j], &QPushButton::clicked, tiles[i][j], &Tile::dig);
            // connect(tiles[i][j], SIGNAL (rightClicked()), tiles[i][j], SLOT (mark()));
            // tiles[i][j]->setText(QString("%1").arg(10 * i + j));

        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

