#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , layout(new QVBoxLayout())
{
    label = new QLabel("Hello World", this);
    label->setAlignment(Qt::AlignCenter);
    this->setCentralWidget(label);

}

MainWindow::~MainWindow()
{
    delete label;
    delete layout;
}

