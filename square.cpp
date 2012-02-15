#include "square.h"


#define SIDE_LENGTH 25
#define HEIGHT SIDE_LENGTH*(sqrt(3))/2
Square::Square()
{
}

Square::Square(int id)
{
    this->_id = id;
    this->_state = false;
}

void Square::nextState()
{
}

void Square::initNeighbours(const AreaI *area, int iy, int ix)
{
    /*
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
                if (i == 0 && j == 0) continue;

                int real_x = ix + i;
                int real_y = iy + j;

                if (real_x == -1) {
                        addNeighbour(area->getNeighbourCellByDir(AreaI::LEFT, real_y));
                } else if (real_x == area->x_size()) {
                        addNeighbour(area->getNeighbourCellByDir(AreaI::RIGHT, real_y));
                } else if (real_y == -1) {
                        addNeighbour(area->getNeighbourCellByDir(AreaI::TOP, real_x));
                } else if (real_y == area->y_size()) {
                        addNeighbour(area->getNeighbourCellByDir(AreaI::BOTTOM, real_x));
                } else {
                        addNeighbour(area->getCell(real_y,real_x));
                }
        }
    }*/
}

void Square::draw(QPainter *p, int y, int x)
{
    x*=SIDE_LENGTH;
    y*=SIDE_LENGTH;

    QPolygon polygon;
    int ar[8] = {x,y, x+SIDE_LENGTH, y, x+SIDE_LENGTH, y+SIDE_LENGTH, x, y+SIDE_LENGTH};

    polygon.putPoints(0, 4, ar);

    p->drawPolygon(polygon);
}
