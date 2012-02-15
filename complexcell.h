#ifndef COMPLEXCELL_H
#define COMPLEXCELL_H

#include "cell.h"
#include <QVector>
#include <QtGui>
#include <QWidget>
using namespace std;

class ComplexCell : public Cell
{
private:
    bool celltype; // true - triangle_up, false - down

public:
    QVector<Cell*> cells;
    virtual QVector<Cell*> subNeighbours(int index)=0;
    Cell* getCell(int index)=0;
 //   virtual void initCell(int id);
    void initNeighbours(const AreaI *area, int ix, int iy);
    virtual void nextState()=0;
    void draw(QPainter *p, int y, int x) {}
    ComplexCell();
};

#endif // COMPLEXCELL_H
