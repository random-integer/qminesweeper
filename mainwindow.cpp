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
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tiles[i][j] = dynamic_cast<Tile*>(ui->gridLayout->itemAtPosition(i, j)->widget());
            // tiles[i][j] = tileij
            connect(tiles[i][j], SIGNAL (clicked()), tiles[i][j], SLOT (dig()));
            connect(tiles[i][j], SIGNAL (rightClicked()), tiles[i][j], SLOT (mark()));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

