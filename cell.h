#ifndef CELL_H
#define CELL_H

#include <QVector>
#include <QtGui>
#include <QWidget>

#include "areai.h"

using namespace std;
class Cell
{
public:
    QVector<Cell*> _neighbours;
    bool _state;
    int _id;
    int _x,_y;
    virtual Cell* getCell(int index)=0;
    //virtual void initCell(int)=0;
    virtual void nextState()=0;
    void addNeighbour(Cell* cell);
    Cell();
    virtual void draw(QPainter *p, int _y, int _x)=0;
    virtual void initNeighbours(const AreaI* area, int ix, int iy) = 0;
};

#endif // CELL_H
