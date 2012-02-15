#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "cell.h"
#include <QtGui>
#include <QWidget>
class Triangle : public Cell
{
public:
    void nextState();
    bool type;
    Triangle(); // up / down
    Triangle(int _id);
    Triangle(int _id, bool def_type);
    Cell* getCell(int index) {return this;}
    void draw(QPainter *p, int _y, int _x);
    void initNeighbours(const AreaI *area, int ix, int iy);
};

#endif // TRIANGLE_H
