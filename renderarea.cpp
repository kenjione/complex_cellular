#include <QtGui>
#include "renderarea.h"
#include <iostream>
#define SIDE_LENGTH 25
#define HEIGHT SIDE_LENGTH*(sqrt(3))/2

RenderArea::RenderArea(QWidget* parent) : QWidget(parent)
{
    cellular = new Cellular(34, 21);
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(next()));
}

RenderArea::~RenderArea() {
    delete timer;
    delete cellular;
}

void RenderArea::next() {
    cellular->next();
    update();
}

void RenderArea::play() {
    timer->start(100);
}

void RenderArea::stop() {
    timer->stop();
}

void RenderArea::save() {
    cellular->save();
}

void RenderArea::restore() {
    cellular->restore();
    update();
}

int RenderArea::getCoordinate(int cell_index) const {
    return cell_index * SIDE_LENGTH + SIDE_LENGTH / 2;
}

int RenderArea::getIndex(int coordinate) const {
    return (coordinate - SIDE_LENGTH / 2) / SIDE_LENGTH;
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(SIDE_LENGTH * (cellular->sizeX() + 1), SIDE_LENGTH * (cellular->sizeY() + 1));
}

void RenderArea::mousePressEvent(QMouseEvent* event) {
    //cellular->invertCell(getIndex(event->x()), getIndex(event->y()));
    //update();
}

void RenderArea::paintEvent(QPaintEvent*)
{
    QBrush brush_state0(Qt::white);
    QBrush brush_state1(Qt::darkGreen);
    QPen pen(Qt::black);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(pen);
    painter.setBrush(brush_state0);

    int x=0;
    int y=0;

    //Area<Square> sq_top(6,4);

    cout << cellular->area[0]->y_size() << " " << cellular->area[0]->x_size() << endl;
    for (int i=0; i<cellular->area[0]->y_size(); i++)
        for (int j=0; j<cellular->area[0]->x_size(); j++)
            cellular->area[0]->drawCell(&painter,i,j);

    cellular->area[0]->join(AreaI::BOTTOM, cellular->area[1]);
    cellular->area[0]->join(AreaI::TOP, cellular->area[1]);
    cellular->area[0]->join(AreaI::LEFT, cellular->area[0]);
    cellular->area[0]->join(AreaI::RIGHT, cellular->area[0]);

    cellular->area[1]->join(AreaI::TOP, cellular->area[0]);
    cellular->area[1]->join(AreaI::LEFT, cellular->area[1]);
    cellular->area[1]->join(AreaI::RIGHT, cellular->area[1]);
    cellular->area[1]->join(AreaI::BOTTOM, cellular->area[0]);

    cellular->area[0]->initNeighbours();
    //cellular->area[1]->initNeighbours();



    //std::cout << cellular->area[0]->getCell(0,0)->neighbours.size();

    for (int i = 0; i<cellular->area[0]->y_size(); i++)
    {
        for (int j = 0; j<cellular->area[0]->x_size(); j++)
            std::cout << cellular->area[0]->getCell(i,j)->_neighbours.size();// << " ; ";
        std::cout << endl;
    }


/*

    // draw squares_top
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<cellular->squares_top[i].size(); j++)
        {
            cellular->squares_top[i][j]->draw(&painter,x,y);
            x+=SIDE_LENGTH;
        }
        x=0;
        y+=SIDE_LENGTH;
    }

    x=0;
    //draw tr_top
    for (int i=0; i<cellular->triangles_top.size(); i++)
    {
        cellular->triangles_top[i]->draw(&painter,x,y);
        if ((i)%2 == 0) x+=SIDE_LENGTH;
    }
    x = SIDE_LENGTH/2;
    y += SIDE_LENGTH*0.9;

    // draw complex
    cellular->complex_triangles[0]->draw(&painter,x,y);
    cellular->complex_triangles[1]->draw(&painter,x+2*SIDE_LENGTH,y);
    cellular->complex_triangles[2]->draw(&painter,x+2*SIDE_LENGTH,y);
    cellular->complex_triangles[3]->draw(&painter,x+5*SIDE_LENGTH,y);

    x = 2*SIDE_LENGTH;
    y+=3*(SIDE_LENGTH*0.88);

    for (int i=0; i<cellular->triangles_bottom.size(); i++)
    {
        cellular->triangles_bottom[i]->draw(&painter,x,y);
        if ((i)%2 == 0) x+=SIDE_LENGTH;
    }

    x = 2*SIDE_LENGTH + SIDE_LENGTH/2;
    y+= SIDE_LENGTH*0.88;

    int t=0;
    for(int i=0; i<4; i++)
    {
        for (int j=0; j<cellular->squares_bottom[i].size(); j++)
        {
            cellular->squares_bottom[i][j]->draw(&painter, x,y);
            x+=SIDE_LENGTH;
        }
        x = 2*SIDE_LENGTH + SIDE_LENGTH/2;
        y+=SIDE_LENGTH;
    }
*/

//    for (int x = 0; x < cellular->sizeX(); ++x) {
//        for (int y = 0; y < cellular->sizeY(); ++y) {
//            if (cellular->cell(x, y) == 0) painter.setBrush(brush_state0);
//            else painter.setBrush(brush_state1);
        
//            painter.save();
//            painter.translate(getCoordinate(x), getCoordinate(y));
//            painter.drawRect(rect);
//            painter.restore();
//        }
//    }

    painter.setRenderHint(QPainter::Antialiasing, false);
       // def
}
