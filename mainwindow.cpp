#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
//    , mButton(std::make_unique<QPushButton>("Hello World", this))
{
    ui->setupUi(this);

    mButton = std::make_unique<QPushButton>("Hello World", this);
    mButton->setGeometry(10, 10, 120, 30);
    ui->okButton->setText("OKI");
//    mButton->addAction
    connect(mButton.get(), SIGNAL (released()), this, SLOT (okButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::okButtonClicked() {
    std::cout << "ok button clicked...\n";

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
