#include <QtGui>
#include "mainwindow.h"

MainWindow::MainWindow() {
   renderArea = new RenderArea(this);
   nextButton = new Button(tr("Next"), this);
   saveButton = new Button(tr("Saveb"), this);
   restoreButton = new Button(tr("Restore"), this);
   playButton = new PlayButton(tr("Play"), tr("Stop"), this);

   connect(nextButton, SIGNAL(clicked()), renderArea, SLOT(next()));
   connect(saveButton, SIGNAL(clicked()), renderArea, SLOT(save()));
   connect(restoreButton, SIGNAL(clicked()), renderArea, SLOT(restore()));
   connect(playButton, SIGNAL(timerStart()), renderArea, SLOT(play()));
   connect(playButton, SIGNAL(timerStop()), renderArea, SLOT(stop()));

   QVBoxLayout *mainLayout = new QVBoxLayout(this);
   mainLayout->addWidget(renderArea);
   mainLayout->addWidget(nextButton, 0, Qt::AlignCenter);
   mainLayout->addWidget(saveButton, 0, Qt::AlignCenter);
   mainLayout->addWidget(restoreButton, 0, Qt::AlignCenter);
   mainLayout->addWidget(playButton, 0, Qt::AlignCenter);
}

MainWindow::~MainWindow() {
    delete renderArea;
    delete nextButton;
    delete playButton;
}

