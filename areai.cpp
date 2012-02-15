#include "areai.h"

AreaI::AreaI()
{
}

Cell* AreaI::getNeighbourCellByDir(Direction dir, int index) const {
        Direction mirror;
        switch (dir) {
        case TOP: mirror = BOTTOM; break;
        case RIGHT: mirror = LEFT; break;
        case BOTTOM: mirror = TOP; break;
        case LEFT: mirror = RIGHT; break;
        }

//		return _neighbours[dir]->getCellByDir(mirror, index);
        return _neighbours.find(dir)->second->getCellByDir(mirror, index);
}
