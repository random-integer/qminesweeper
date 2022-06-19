#include "tile.h"
#include <QPushButton>

Tile::Tile(QWidget *parent)
    : QPushButton{parent}
    , isMine(false)
{

}

bool Tile::getIsMine() {
    return this->isMine;
}

void Tile::setIsMine(bool x = true) {
    this->isMine = x;
    return;
}
