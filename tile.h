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

private:
    bool mine;
    int marked;  // 0: not marked, 1: flagged, 2: question marked
private slots:
    void dig();
    void mark();
    void mousePressEvent(QMouseEvent *e);

};

#endif // TILE_H
