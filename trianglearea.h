#ifndef TRIANGLEAREA_H
#define TRIANGLEAREA_H

#include "area.h"
#include "triangle.h"
#include "triangleiterator.h"

class TriangleArea : public Area<Triangle>
{
public:
    TriangleArea(int x_size, int y_size = 1):Area<Triangle>(x_size, y_size ) {}
protected:
    NeighboursIterator* createIterator() {
        return new TriangleIterator(this);
    }
};

#endif // TRIANGLEAREA_H
