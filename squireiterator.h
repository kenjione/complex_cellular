#ifndef SQUIREITERATOR_H
#define SQUIREITERATOR_H

#include "neighboursiterator.h"


class SquireIterator : public NeighboursIterator
{
public:
    SquireIterator(AreaI* area) : NeighboursIterator(area) { }
    void first(){
        _ix = -1;
        _iy = -1;
    }
    void next() {
        if (_ix==2) {_iy++; _ix=-1;}
        if (_ix==0 && _iy==0) _ix++;
        _ix++;
    }
    bool isDone() {
        return _iy < 2;
    }
};

#endif // SQUIREITERATOR_H
