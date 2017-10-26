#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  hide_window_ = new hide_frame(ui->centralWidget);
}
void MainWindow::resizeEvent(QResizeEvent * /*size*/) {
  hide_window_->RefreshPos();
}
MainWindow::~MainWindow() { delete ui; }
