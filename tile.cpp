#include "tile.h"
#include <QPushButton>
#include <QTextStream>

Tile::Tile(QWidget *parent)
    : QPushButton{parent},
    mine(false),
    marked(0) {
    return;
}

void Tile::mousePressEvent(QMouseEvent *e) {
    if (e->button() == Qt::RightButton) {
        emit rightClicked();
    } else if (e->button() == Qt::LeftButton) {
        emit clicked();
    } else {
        emit middleClicked();
    }
}

void Tile::detonate() {
    if (this->isEnabled()) {
        if (this->mine) {
            switch (this->marked) {
            case 0:
                this->setText("bomb");
                break;
            case 1:
                break;
            case 2:
                this->setText("? bomb");
            }
        } else { // not a mine
            switch (this->marked) {
            case 0:
                break;
            case 1:
                this->setText("⚑X");
                break;
            case 2:
                this->setText("?X");
            }
        }
    }
}
