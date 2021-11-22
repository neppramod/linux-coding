#include "window.h"

#include <QButtonGroup>
#include <QApplication>

Window::Window(QWidget *parent) : QWidget(parent)
{
  setFixedSize(320, 230);
  setWindowTitle("Button Game");

  checkBoxes[0] = new QCheckBox("1", this);
  checkBoxes[0]->setGeometry(10, 10, 50, 30);
  checkBoxes[1] = new QCheckBox("2", this);
  checkBoxes[1]->setGeometry(10, 30, 50, 30);
  checkBoxes[2] = new QCheckBox("3", this);
  checkBoxes[2]->setGeometry(10, 50, 50, 30);

  radioButtons[0] = new QRadioButton("1", this);
  radioButtons[0]->setGeometry(100, 10, 50, 30);
  radioButtons[1] = new QRadioButton("2", this);
  radioButtons[1]->setGeometry(100, 30, 50, 30);
  radioButtons[2] = new QRadioButton("3", this);
  radioButtons[2]->setGeometry(100, 50, 50, 30);
  
  QButtonGroup *radioButtonGroup = new QButtonGroup(this);
  radioButtonGroup->addButton(radioButtons[0]);
  radioButtonGroup->addButton(radioButtons[1]);
  radioButtonGroup->addButton(radioButtons[2]);

  pushButtons[0] = new QPushButton("1", this);
  pushButtons[0]->setGeometry(10, 100, 80, 30);

  pushButtons[1] = new QPushButton("2", this);
  pushButtons[1]->setGeometry(100, 100, 80, 30);

  
  pushButtons[2] = new QPushButton("Quit", this);
  pushButtons[2]->setGeometry(10, 140, 80, 30);
  pushButtons[2]->setVisible(false);

  connect(pushButtons[1], SIGNAL (clicked()), this, SLOT(pushButton2Clicked()));
  connect(this, SIGNAL(quitButtonConditionFulfilled()), this, SLOT(pushButton3Clicked()));
  connect(pushButtons[2], SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
}

// can use checked version of slot for clicked as well, but signal and slot needs to match method signature
// We could check all matched consition here, but for let's do using signal
void Window::pushButton2Clicked()
{
  if (checkBoxes[1]->checkState() == Qt::Checked && radioButtons[2]->isChecked()) {
      emit quitButtonConditionFulfilled();
  } else {
    // We could have just enabled the button here, here we are setting visible to false for pushButton[2]
    // Notice, we don't disable for button[0] click.
    // We could add another slot for pushButton[0] to do following
    pushButtons[2]->setVisible(false);
  }

}

void Window::pushButton3Clicked()
{
  pushButtons[2]->setVisible(true);
}
