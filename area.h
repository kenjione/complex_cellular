#ifndef AREA_H
#define AREA_H

#include "areai.h"
#include "cell.h"

#define SIDE_LENGTH 25
#define HEIGHT SIDE_LENGTH*(sqrt(3))/2

template<class CellType>
class Area : public AreaI {
public:
        Area(int x_size, int y_size = 1) : AreaI(x_size, y_size) {
            _cells = new CellType*[y_size];
            for (int iy = 0; iy < y_size; ++iy) {
                    _cells[iy] = new CellType[x_size];
            }
            initIterator();
        }

        virtual ~Area() {
                for (int i = 0; i < y_size(); ++i) delete [] _cells[i];
                delete [] _cells;
        }

        void initNeighbours() {
                for (int iy = 0; iy < y_size(); ++iy) {
                        for (int ix = 0; ix < x_size(); ++ix) {
                            this->_neighboursIter->setup(iy,ix);
                            for (this->_neighboursIter->first(); !this->_neighboursIter->isDone(); this->_neighboursIter->next()) {
                                // esli na granice
                                _neighboursIter = neighbourIterator();

                                if (ix != 0 || ix != x_size() - 1 || iy != 0 || iy != y_size() - 1) continue;

                                this->_cells[iy][ix].addNeighbour(this->_neighboursIter->current());
                            }
                        }
                }
        }

        Cell* getCell(int iy, int ix) const {
            return &_cells[iy][ix];
        }

        void drawCell(QPainter *p, int y, int x) {
            getCell(y,x)->draw(p,y,x);
        }

protected:
        Cell* getCellByDir(Direction dir, int index) const {
                int new_index = -1;
                Direction new_dir;

                switch (dir) {
                case TOP:
                case BOTTOM:
                        if (index == -1) {
                                new_index = x_size() - 1;
                                new_dir = LEFT;
                        } else if (index == x_size()) {
                                new_index = 0;
                                new_dir = RIGHT;
                        }
                        break;
                case RIGHT:
                case LEFT:
                        if (index == -1) {
                                new_index = y_size() - 1;
                                new_dir = TOP;
                        } else if (index == y_size()) {
                                new_index = 0;
                                new_dir = BOTTOM;
                        } else if (index == y_size()-1) {
                                //new_index =  ???
                        }

                        break;
                }

                if (new_index != -1) {
                        return getNeighbourCellByDir(new_dir, new_index);
                }

                switch (dir) {
                case TOP: return &_cells[0][index];
                case RIGHT: return &_cells[index][x_size() - 1];
                case BOTTOM: return &_cells[y_size() - 1][index];
                case LEFT: return &_cells[index][0];
                }
        }

private:
        CellType** _cells;
        void initIterator() {
                _neighboursIter = this->createIterator();
        }
};

#endif // AREA_H
