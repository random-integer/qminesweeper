#include "tile.h"
#include <QPushButton>
#include <iostream>

Tile::Tile(QWidget *parent)
    : QPushButton{parent}
    , mine(false)
    , marked(0)
{

}

bool Tile::getmine() {
    return this->mine;
}

void Tile::setmine(bool x = true) {
    this->mine = x;
    return;
}

void Tile::mousePressEvent(QMouseEvent *e) {
    if (e->button() == Qt::RightButton) {
        emit rightClicked();
    }
    return;
}

void Tile::dig() {
    switch (marked) {
    case 0:
        if (mine) {
            emit explode();
        } else {
            // TODO: make button disappear
        }
        break;
    case 1:
    case 2:
        return;
        break;
    default:
        std::cout << "wtf";
    }

}

void Tile::mark() {
    this->marked += 1;
    this->marked %= 3;
    return;
}
