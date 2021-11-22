#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>

class QPushButton;
class QCheckBox;
class QRadioButton;

class Window : public QWidget
{
  Q_OBJECT
 public:
  explicit Window(QWidget *parent = NULL);
 private:
  QCheckBox* checkBoxes[3];
  QRadioButton* radioButtons[3];
  QPushButton* pushButtons[3];

 signals:
  void quitButtonConditionFulfilled();
  
  private slots:
    void pushButton2Clicked();
    void pushButton3Clicked();
};

#endif  // WINDOW_H
