#ifndef HIDE_FRAME_H
#define HIDE_FRAME_H

#include <QFrame>
#include <QRect>
#include <iostream>
namespace Ui {
class hide_frame;
}

class hide_frame : public QFrame {
  Q_OBJECT

public:
  explicit hide_frame(QWidget *parent = 0);
  ~hide_frame();

  void RefreshPos();

private:
  void MaxMode();
  void MinMode();

  void SwitchMode();
  void ResetGeometry(QWidget *widget, QRect from_rect, QRect to_rect);

private:
  Ui::hide_frame *ui;
  int show_mode_ = 0; // 0:隐藏模式 1：显示模式
  int min_height_ = 0;
  int max_height_ = 0;

  QWidget *parent_widget_ = nullptr;
};

#endif // HIDE_FRAME_H
