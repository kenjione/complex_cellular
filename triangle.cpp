#include "triangle.h"
#define SIDE_LENGTH 25
#define HEIGHT SIDE_LENGTH*(sqrt(3))/2


Triangle::Triangle()
{
}

Triangle::Triangle(int id)
{
    this->_id = id;
    (id % 2 == 0) ? this->type = false : this->type = true;   // true - up , false - down
    this->_state = false;
}

void Triangle::nextState()
{
}

Triangle::Triangle(int id, bool def_type)
{
    this->_id = id;
    this->type = def_type;
}


void Triangle::draw(QPainter *p, int y, int x)
{
    if (x%2 == 0) this->type = false;
    else {this->type = true; x*=SIDE_LENGTH;}

    if (this->_state==true) p->setBrush(Qt::blue);
    else p->setBrush(Qt::white);

    if (this->type == false)
    {
        QPolygon polygon;
        int ar[6] = {x,y, x+SIDE_LENGTH, y, x+SIDE_LENGTH/2, y+SIDE_LENGTH*0.87};
        polygon.putPoints(0, 3, ar);

        p->drawPolygon(polygon);

    } else
    {
    QPolygon polygon;
    int ar[6] = {x,y, x+SIDE_LENGTH/2+1.5, y+SIDE_LENGTH*0.95, x-SIDE_LENGTH/2-1.5, y+SIDE_LENGTH*0.95};
    polygon.putPoints(0, 3, ar);

    p->drawPolygon(polygon);
    }
}

void Triangle::initNeighbours(const AreaI *area, int ix, int iy)
{
}
