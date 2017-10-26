#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "hide_frame.h"
#include <QMainWindow>
#include <QResizeEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  void resizeEvent(QResizeEvent *size);

private:
  Ui::MainWindow *ui;
  hide_frame *hide_window_ = nullptr;
};

#endif // MAINWINDOW_H
