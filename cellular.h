#ifndef CELLULAR_H
#define CELLULAR_H

#define STATES_NUM 3

#include <QVector>
//#include "cell.h"
#include "square.h"
#include "triangle.h"
#include "complextriangledown.h"
#include "complextriangleup.h"
#include "area.h"
#include "squarearea.h"
#include "trianglearea.h"

class Cellular
{
public:

    explicit Cellular(int size_x, int size_y);
    virtual ~Cellular();

    void save();
    void restore();

    void next();
    int sizeX() const { return size_x; }
    int sizeY() const { return size_y; }
    int cell(int x, int y) const { /*return cells[curr_state_index][x][y];*/ }

    void invertCell(int i, int j) {
        //int state = this->area[i][j]->state; //cells[curr_state_index][x][y];
        //this->area[i][j]->state = (state==0) ? 1 : 0;

        //cells[curr_state_index][x][y] = (state == 0) ? 1 : 0;
    }
    //QVector<Cell*> cells[STATES_NUM];

    void addNeighbourToCell(int x, int y);
    QVector<Cell*> squares_top[4], triangles_top, complex_triangles, triangles_bottom, squares_bottom[4];
    QVector<AreaI*> area;

private:
    void copyCells(int to_state, int from_state);

    void zerofile();
    void firstInit();

    int getNextState(int x, int y) const;
    int getStateByNums(int curr_state, int nums) const;

    int size_x, size_y;

    //int** cells[STATES_NUM];

    int curr_state_index;
};

#endif // CELLULAR_H
