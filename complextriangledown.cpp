#include "complextriangledown.h"


ComplexTriangleDown::ComplexTriangleDown()
{

}

ComplexTriangleDown::ComplexTriangleDown(int id)
{
    this->_id = id;
    for (int i=1; i<4; i++)
    {
        subCells.push_back(new Triangle(i,false));
    }

    if (this->_id == 0)
        subCells.push_back(new Hexagon(1, false));
    else subCells.push_back(new Hexagon(1, true));
}

QVector<Cell*> ComplexTriangleDown::subNeighbours(int index)
{

    //return 1;
}

void ComplexTriangleDown::initNeighbours(const AreaI *area, int ix, int iy){}

void ComplexTriangleDown::draw(QPainter *p, int y, int x)
{
    // draw 1st triangle
    if (this->_id == 0) subCells[0]->draw(p,x+5*SIDE_LENGTH,y);
    else
    subCells[0]->draw(p,x,y);

    // draw 2nd triangle
    if (this->_id == 0) subCells[1]->draw(p,x+SIDE_LENGTH,y);
    else
    subCells[1]->draw(p,x+2*SIDE_LENGTH,y);

    // draw 3rd triangle
    if (this->_id == 0) subCells[2]->draw(p,x+6*SIDE_LENGTH, y+2*0.88*SIDE_LENGTH);
    else
    subCells[2]->draw(p,x+SIDE_LENGTH, y+2*0.88*SIDE_LENGTH);

    // draw hex
    if (this->_id == 0) subCells[3]->draw(p,x,y);
    else
    subCells[3]->draw(p,x+SIDE_LENGTH,y);
}

Cell* ComplexTriangleDown::getCell(int index)
{
    return subCells[index];
}

ComplexTriangleDown::~ComplexTriangleDown(){
   // delete Hexagon

}
