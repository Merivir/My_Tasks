#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    layout = new QVBoxLayout(centralWidget);

    line1 = new QLineEdit();
    line1->setPlaceholderText("Enter Name...");
    line2 = new QLineEdit();
    line2->setPlaceholderText("Enter Surname...");
    line3 = new QLineEdit();
    line3->setPlaceholderText("Enter Age...");

    button = new QPushButton("Send", this);

    layout->addWidget(button);
    layout->addWidget(line1);
    layout->addWidget(line2);
    layout->addWidget(line3);

    connect(button, &QPushButton::clicked, this, &MainWindow::checkMessage);
}

void MainWindow::checkMessage() {
    if (line1->text().trimmed().isEmpty() ||
        line2->text().trimmed().isEmpty() ||
        line3->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Warning", "The input is empty.");
    } else {
        QMessageBox::information(this, "Input Received", "You entered: " + line1->text() + line2->text() + line3->text());
        line1->clear();
        line2->clear();
        line3->clear();
    }
}

MainWindow::~MainWindow()
{
    delete layout;
    delete line1;
    delete line2;
    delete line3;
    delete button;
}

