#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include "cellular.h"

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget* parent = 0);
    virtual ~RenderArea();

    QSize minimumSizeHint() const;

//signals:
public slots:
    void next();
    void play();
    void stop();

    void save();
    void restore();

protected:
    int getCoordinate(int cell_index) const;
    int getIndex(int coordinate) const;

    void mousePressEvent (QMouseEvent* event);
    void paintEvent(QPaintEvent* event);

private:
    Cellular* cellular;
    QTimer* timer;
};

#endif // RENDERAREA_H
