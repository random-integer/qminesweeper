#ifndef TILE_H
#define TILE_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

class Tile : public QPushButton
{
    Q_OBJECT
public:
    explicit Tile(QWidget *parent = nullptr);
    void setmine(bool x);
    bool getmine();

signals:
    void rightClicked();
    void explode();

private:
    bool mine;
    int marked;  // 0: not marked, 1: flagged, 2: question marked
public slots:
    void dig();
    void secondaryDig();  // called when a neighboring cell with a count of 0 is dug()
    void mark();
    void mousePressEvent(QMouseEvent *e);

};

#endif // TILE_H
