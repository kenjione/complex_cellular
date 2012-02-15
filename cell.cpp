#include "cell.h"



Cell::Cell()
{

}

void Cell::addNeighbour(Cell *cell)
{
    _neighbours.push_back(cell);
}
