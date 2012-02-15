#ifndef COMPLEXTRIANGLEDOWN_H
#define COMPLEXTRIANGLEDOWN_H

#define SIDE_LENGTH 25
#define HEIGHT SIDE_LENGTH*(sqrt(3))/2

#include <QVector>
//#include "complexcell.h"
#include "cell.h"
#include "hexagon.h"
#include "triangle.h"
#include <QtGui>
#include <QWidget>
class ComplexTriangleDown : public Cell
{
public:
    QVector<Cell*> subCells;
    Cell* getCell(int index);
    QVector<Cell*> subNeighbours(int index);
    ComplexTriangleDown();
    ComplexTriangleDown(int _id);
    void nextState() {}
    void draw(QPainter *p, int _y, int _x);
    void initNeighbours(const AreaI *area, int ix, int iy);
    ~ComplexTriangleDown();
};

#endif // COMPLEXTRIANGLEDOWN_H
