#include "cellular.h"
#include <iostream>


#define SQTOP 6
#define TRTOP 12
#define TRCOMPLEX 4
#define TRBOTTOM 12
#define SQBOTTOM 6



Cellular::Cellular(int size_x, int size_y) : size_x(size_x), size_y(size_y), curr_state_index(0) {


    area.push_back(new SquareArea(6,4));
    area.push_back(new TriangleArea(6,2));




/*
    for (int i=0; area.size(); i++)
        delete area[i];*/
}


void Cellular::addNeighbourToCell(int x, int y)
{
}


Cellular::~Cellular() {
}

void Cellular::save() {
    }

void Cellular::restore() {

}

void Cellular::copyCells(int to_state, int from_state) {
}

void Cellular::zerofile() {
}

void Cellular::firstInit() {/*
    zerofile();
    cells[curr_state_index][1][1] = 1;
    cells[curr_state_index][3][1] = 1;
    cells[curr_state_index][2][2] = 1;
    cells[curr_state_index][3][2] = 1;
    cells[curr_state_index][2][3] = 1;*/
}

void Cellular::next() {
}

int Cellular::getNextState(int x, int y) const {
}

int Cellular::getStateByNums(int curr_state, int nums) const {
}

