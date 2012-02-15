#ifndef NEIGHBOURSITERATOR_H
#define NEIGHBOURSITERATOR_H

#include "areai.h"

class NeighboursIterator
{
public:
    void setup(int ix, int iy) {}

    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;

    Cell* current() {
        return _area->getCell(_iy, _ix);
    }
protected:
    NeighboursIterator(AreaI* const area): _area(area) {}
    int _ix;
    int _iy;
    AreaI* _area;
};

#endif // NEIGHBOURSITERATOR_H
