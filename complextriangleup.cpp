#include "complextriangleup.h"

ComplexTriangleUp::ComplexTriangleUp()
{
}

ComplexTriangleUp::ComplexTriangleUp(int id)
{
    this->_id = id;
    for (int i=1; i<4; i++)
    {
        subCells.push_back(new Triangle(i,true));
    }

    subCells.push_back(new Hexagon(4,true));
}

void ComplexTriangleUp::initNeighbours(const AreaI *area, int ix, int iy){}
QVector<Cell*> ComplexTriangleUp::subNeighbours(int index)
{
    //return 1;
}

void ComplexTriangleUp::draw(QPainter *p, int y, int x)
{
    // draw 1st triangle
    subCells[0]->draw(p,x,y);

    // draw 2nd triangle
    if (this->_id == 1) subCells[1]->draw(p,6*SIDE_LENGTH + (x-SIDE_LENGTH/2 - SIDE_LENGTH/2), y + SIDE_LENGTH*0.87 + SIDE_LENGTH*0.87);
        else subCells[1]->draw(p,x-SIDE_LENGTH/2 - SIDE_LENGTH/2, y + SIDE_LENGTH*0.87 + SIDE_LENGTH*0.87);

    // draw 3rd triangle
    subCells[2]->draw(p,x+SIDE_LENGTH/2 + SIDE_LENGTH/2, y + SIDE_LENGTH*0.87 + SIDE_LENGTH*0.87);

    // draw hex
    subCells[3]->draw(p,x-SIDE_LENGTH/2,y+SIDE_LENGTH*0.87);
}

Cell* ComplexTriangleUp::getCell(int index)
{
    return subCells[index];
}
