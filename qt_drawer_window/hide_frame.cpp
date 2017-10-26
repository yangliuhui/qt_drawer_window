#include "hide_frame.h"
#include "ui_hide_frame.h"
#include <QPropertyAnimation>
hide_frame::hide_frame(QWidget *parent)
    : QFrame(parent), ui(new Ui::hide_frame) {
  ui->setupUi(this);

  parent_widget_ = parent;
  min_height_ = ui->frame_title->height();
  max_height_ = this->height();

  std::cout << "max_height:" << max_height_ << std::endl;
  std::cout << "min_height:" << min_height_ << std::endl;

  connect(ui->btn_mode, &QPushButton::clicked, this, &hide_frame::SwitchMode);
}
hide_frame::~hide_frame() { delete ui; }
void hide_frame::MaxMode() {
  show_mode_ = 1;
  int to_pos_y =
      parent_widget_->pos().ry() + parent_widget_->height() - max_height_;
  QRect to_rect = QRect(parent_widget_->pos().rx(), to_pos_y,
                        parent_widget_->width(), this->height());
  ResetGeometry(this, this->geometry(), to_rect);
}
void hide_frame::MinMode() {
  show_mode_ = 0;
  int to_pos_y =
      parent_widget_->pos().ry() + parent_widget_->height() - min_height_;
  QRect to_rect = QRect(parent_widget_->pos().rx(), to_pos_y,
                        parent_widget_->width(), this->height());
  ResetGeometry(this, this->geometry(), to_rect);
}

void hide_frame::SwitchMode() {
  if (show_mode_ == 0) {
    MaxMode();
  } else {
    MinMode();
  }
}
void hide_frame::RefreshPos() {
  if (show_mode_ == 0) {
    MinMode();
  } else {
    MaxMode();
  }
}

void hide_frame::ResetGeometry(QWidget *widget, QRect from_rect,
                               QRect to_rect) {
  QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
  animation->setDuration(1000);
  animation->setStartValue(from_rect);
  animation->setEndValue(to_rect);
  animation->setEasingCurve(QEasingCurve::OutElastic);
  animation->start(QAbstractAnimation::DeleteWhenStopped);
}
