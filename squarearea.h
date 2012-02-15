#ifndef SQUAREAREA_H
#define SQUAREAREA_H

#include "area.h"
#include "square.h"
#include "squireiterator.h"

class SquareArea : public Area<Square>
{
public:
    SquareArea(int x_size, int y_size = 1):Area<Square>(x_size, y_size ) {
    }
protected:
    NeighboursIterator* createIterator() {
        return new SquireIterator(this);
    }
};

#endif // SQUAREAREA_H
