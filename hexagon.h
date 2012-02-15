#ifndef HEXAGON_H
#define HEXAGON_H

#define SIDE_LENGTH 25
#define HEIGHT SIDE_LENGTH*(sqrt(3))/2
#include "cell.h"
#include <QtGui>
#include <QWidget>
class Hexagon : public Cell
{
public:
    bool type; // true - simple, false - parsed;
    Hexagon();
    Hexagon(int _id);
    Hexagon(int _id, bool type);
    void nextState();
    Cell* getCell(int index) {return this;}
    void draw(QPainter *p, int _y, int _x);
    void initNeighbours(const AreaI *area, int ix, int iy);
};

#endif // HEXAGON_H
