#include "tile.h"
#include <QPushButton>

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
    if (e->button()==Qt::RightButton) {
        emit rightClicked();
    }
    return;
}

void Tile::dig() {

}

void Tile::mark() {
    this->marked += 1;
    this->marked %= 3;
    return;
}
