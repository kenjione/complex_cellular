#ifndef TRIANGLEITERATOR_H
#define TRIANGLEITERATOR_H

#include "neighboursiterator.h"

class TriangleIterator : public NeighboursIterator
{
public:
    TriangleIterator(AreaI* area) : NeighboursIterator(area) { }
    void first(){}
    void next() {}
    bool isDone() {}
};

#endif // TRIANGLEITERATOR_H
