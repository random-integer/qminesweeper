#ifndef TILE_H
#define TILE_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

class Tile : public QPushButton {
    Q_OBJECT
public:
    explicit Tile(QWidget *parent = nullptr);
    bool mine;
    int marked;  // 0: not marked, 1: flagged, 2: question marked
public slots:
    void detonate();

signals:
    void rightClicked();
    void middleClicked();

private slots:
    void mousePressEvent(QMouseEvent *e);
};

#endif // TILE_H
