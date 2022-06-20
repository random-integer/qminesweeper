#include "tile.h"
#include <QPushButton>
#include <QTextStream>

Tile::Tile(QWidget *parent)
    : QPushButton{parent}
    , mine(false)
    , marked(0) {
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
        }
    }
}
