#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , count(0)
    , layout(nullptr)
    , label(nullptr)
    , button(nullptr)
{
    QWidget *centralWidget = new QWidget(this);
    layout = new QVBoxLayout(centralWidget);
    label = new QLabel("0", this);

    button = new QPushButton("Click", centralWidget);

    layout->addWidget(button);
    layout->addWidget(label);
    setCentralWidget(centralWidget);

    connect(button, &QPushButton::clicked, this, &MainWindow::buttonHandler);
}

MainWindow::~MainWindow()
{
    delete centralWidget;	
    delete layout;
    delete label;
    delete button;
}

void MainWindow::buttonHandler()
{
    ++count;
    label->setText(QString::number(count));
    setLayout(layout);
}

