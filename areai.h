#ifndef AREAI_H
#define AREAI_H

#include <QtGui>
#include <QWidget>
#include <QMap>
#include <iostream>


using namespace std;

class Cell;
class NeighboursIterator;

class AreaI
{
public:
    AreaI();
    enum Direction { TOP, RIGHT, BOTTOM, LEFT };

    int x_size() const { return _x_size; }
    int y_size() const { return _y_size; }

    void join(Direction dir, const AreaI* other) {
            _neighbours[dir] = other;
    }

    virtual void initNeighbours() = 0;
    virtual Cell* getCell(int iy, int ix) const = 0;

    Cell* getNeighbourCellByDir(Direction dir, int index) const;

    NeighboursIterator* neighbourIterator() {
        return this->createIterator();
    }
    virtual void drawCell(QPainter *p, int x, int y) = 0;


    bool onBorder(int iy, int ix) {}
    QVector<AreaI*> neighbourAreas() {}
    int neighbourX() {}
    int neighbourY() {}
    NeighboursIterator* _neighboursIter;
    Direction findDirection() {}
private:
    int _x_size, _y_size;
    map< Direction, const AreaI* > _neighbours;

protected:
    AreaI(int x_size, int y_size) : _x_size(x_size), _y_size(y_size) {}
    virtual Cell* getCellByDir(Direction dir, int index) const = 0;
    virtual NeighboursIterator* createIterator() = 0;
};

#endif // AREAI_H
