#include "tile.h"
#include <QPushButton>
#include <QTextStream>

Tile::Tile(QWidget *parent)
    : QPushButton{parent}
    , mine(false)
    , marked(0)
{
    return;
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

/*
void Tile::dig() {
    this->setText("dug");
    switch (marked) {
    case 0: // not marked
        if (mine) {
            emit explode();
        } else {
            // TODO: make button disappear
        }
        break;
    case 1: // flagged
    case 2: // question marked
        return;
        break;
    }

}

void Tile::mark() {
    this->marked += 1;
    this->marked %= 3;
    return;
}

void Tile::secondaryDig() {
    return;
}
*/
