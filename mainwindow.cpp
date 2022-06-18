#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *tiles[10][10];
    // tiles[row][column]
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tiles[i][j] = dynamic_cast<QPushButton *>(ui->gridLayout->itemAtPosition(i, j)->widget());
            // tiles[i][j] = tileij
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

