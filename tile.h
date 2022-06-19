#ifndef TILE_H
#define TILE_H

#include <QWidget>
#include <QPushButton>

class Tile : public QPushButton
{
    Q_OBJECT
public:
    explicit Tile(QWidget *parent = nullptr);
    void setIsMine(bool x);
    bool getIsMine();

private:
    bool isMine;

};

#endif // TILE_H
