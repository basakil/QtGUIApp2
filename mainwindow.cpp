#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QMessageBox>
#include "EmployeeDB.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
//    , mButton(std::make_unique<QPushButton>("Hello World", this))
{
    ui->setupUi(this);

    mButton = make_unique<QPushButton>("Hello World", this);
    mButton->setGeometry(10, 10, 120, 30);
    mButton.get()->released();
    connect(mButton.get(), SIGNAL (released()), this, SLOT (okButtonClicked()));
    connect(ui->exitButton, SIGNAL (released()), this, SLOT (okButtonClicked()));

    cout << "dabaduu" << endl;
    Records::Employee employee1("ali", "veli");
    cout << "Employee == [" << employee1 << "]." << endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::okButtonClicked() {
    cout << "some button is clicked..." << endl;
    cout.flush();

    QAbstractButton *button = dynamic_cast<QAbstractButton*>(sender());
    if (button) {
        cout << "clicked button text is: " << button->text().toUtf8().constData() << endl;
    }

    QMessageBox msgBox;
    msgBox.setText("Exit.");
    msgBox.setInformativeText("Exit the application?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();

    switch (ret) {
      case QMessageBox::Ok:
          QApplication::quit();
          break;
      case QMessageBox::Cancel:
      default:
          break;
    }

}
