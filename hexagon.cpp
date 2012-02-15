#include "hexagon.h"

Hexagon::Hexagon()
{
}

Hexagon::Hexagon(int id)
{
    this->_id = id;
}

Hexagon::Hexagon(int id, bool type)
{
    this->_id = id;
    this->type = type;
    this->_state = false;
}

void Hexagon::nextState()
{
}

void Hexagon::initNeighbours(const AreaI *area, int ix, int iy){}

void Hexagon::draw(QPainter *p, int x, int y)
{
    QPolygon polygon;
    this->_state = false;
    switch(this->type)
    {
    case true:  // unbroken
    {
        this->type = true;

        int ar[12] = {x-0.7,y+2.5,
                      x+SIDE_LENGTH, y+2.5,
                      x+SIDE_LENGTH + SIDE_LENGTH/2,y+SIDE_LENGTH*0.88,
                      x+SIDE_LENGTH, y+SIDE_LENGTH*0.88 + SIDE_LENGTH*0.88,
                      x, y+SIDE_LENGTH*0.88 + SIDE_LENGTH*0.88,
                      x-SIDE_LENGTH/2+0.05, y+SIDE_LENGTH*0.88
                     };
        polygon.putPoints(0, 6, ar);
        p->drawPolygon(polygon);
        break;
    }
    case false: // broken
    {
        this->type = false;
        polygon;
        int r[8] = {x,y,
                    x+SIDE_LENGTH,y,
                    x+1.5*SIDE_LENGTH, y+0.88*SIDE_LENGTH,
                    x+SIDE_LENGTH,y+2*0.88*SIDE_LENGTH
                     };
        polygon.putPoints(0, 4, r);

        p->drawPolygon(polygon);

        x+=(SIDE_LENGTH*6);
        int l[8] = {x,y,
                   x+SIDE_LENGTH,y+2*0.88*SIDE_LENGTH,
                   x,y+2*0.88*SIDE_LENGTH,
                   x-SIDE_LENGTH/2, y+0.88*SIDE_LENGTH
                   };

        polygon.putPoints(0, 4, l);
        p->drawPolygon(polygon);
        break;
    }
    }

    // simple case:
/*
    this->type = true;
    QPolygon polygon;
    int ar[12] = {x-0.7,y+2.5,
                  x+SIDE_LENGTH*0.99, y+2.5,
                  x+SIDE_LENGTH*0.99 + SIDE_LENGTH/2,y+SIDE_LENGTH*0.9,
                  x+SIDE_LENGTH*0.9, y+SIDE_LENGTH*0.9 + SIDE_LENGTH*0.9,
                  x, y+SIDE_LENGTH*0.9 + SIDE_LENGTH*0.9,
                  x-SIDE_LENGTH/2+0.05, y+SIDE_LENGTH*0.95
                 };
    polygon.putPoints(0, 6, ar);
    p->drawPolygon(polygon);

    // parsed case:

    this->type = false;
    QPolygon polygon;
    int r[8] = {x,y,
                x+SIDE_LENGTH,y,
                x+1.5*SIDE_LENGTH, y+0.88*SIDE_LENGTH,
                x+SIDE_LENGTH,y+2*0.88*SIDE_LENGTH
                 };
    polygon.putPoints(0, 4, r);

    p->drawPolygon(polygon);


    x+=100;
    int l[8] = {x,y,
               x+SIDE_LENGTH,y+2*0.88*SIDE_LENGTH,
               x,y+2*0.88*SIDE_LENGTH,
               x-SIDE_LENGTH/2, y+0.88*SIDE_LENGTH
               };

    polygon.putPoints(0, 4, l);
    p->drawPolygon(polygon);
*/
}
