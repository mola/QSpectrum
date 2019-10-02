#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#define FFTBUFFER 256
#define FFTSIZE 256 * 10
namespace Ui
{
class MainWindow;
}

class CPlotter;

class MainWindow: public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

  ~MainWindow();

private slots:
  void  timeout();

private:
  Ui::MainWindow *ui;
  QTimer         *mTimer;
  float           mData[FFTBUFFER][FFTSIZE];
  int             mRow;
  CPlotter       *mPlotter;
};

#endif // MAINWINDOW_H
