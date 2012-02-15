#ifndef SQUARE_H
#define SQUARE_H
#include <QtGui>
#include <QWidget>
#include "cell.h"

class Square : public Cell
{
public:
    void nextState();
    Square();
    Square(int _id);
    Cell* getCell(int index) { return this; }
    void draw(QPainter *p, int _y, int _x);
    void initNeighbours(const AreaI *area, int iy, int ix);
};

#endif // SQUARE_H
