#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widgets/plotter.h"
#include "widgets/bookmarks.h"

MainWindow::MainWindow(QWidget *parent):
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  Bookmarks::create();
  mPlotter = new CPlotter(this);
// mPlotter->setFftPlotColor(Qt::red);
// mPlotter->setFftRange(244.1, (0.1 * FFTSIZE));
// mPlotter->setFftCenterFreq(25.0);
// mPlotter->setHiLowCutFrequencies(10, 200);
  mPlotter->update();
  setCentralWidget(mPlotter);

  mRow = 0;

  for (int i = 0; i < FFTBUFFER; i++)
  {
    for (int j = 0; j < FFTSIZE; j++)
    {
      mData[i][j] = ((double(rand()) / RAND_MAX) * 128) * -1;
    }
  }

  mTimer = new QTimer();
  mTimer->setInterval(1000.0 / 30.0);
  connect(mTimer, &QTimer::timeout, this, &MainWindow::timeout);
  mTimer->start();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void  MainWindow::timeout()
{
  float  d = double(rand()) / RAND_MAX;

  mPlotter->setNewFftData(mData[mRow], FFTSIZE);
  mRow++;

  if (mRow > FFTBUFFER - 1)
  {
    mRow = 0;
  }
}
