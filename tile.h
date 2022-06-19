#ifndef TILE_H
#define TILE_H

#include <QWidget>
#include <QPushButton>

class Tile : public QPushButton
{
    Q_OBJECT
public:
    explicit Tile(QWidget *parent = nullptr);

signals:

};

#endif // TILE_H
