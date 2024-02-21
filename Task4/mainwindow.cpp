#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    centralWidget = new QWidget(this);
    layout = new QVBoxLayout(centralWidget);

    input = new QLineEdit();
    list = new QListWidget();
    addButton = new QPushButton("Add Task");
    removeButton = new QPushButton("Remove Tasks");

    layout->addWidget(input);
    layout->addWidget(list);
    layout->addWidget(addButton);
    layout->addWidget(removeButton);
    setCentralWidget(centralWidget);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addTask);

    connect(removeButton, &QPushButton::clicked, this, &MainWindow::removeTask);
}

void MainWindow::addTask() {
     QString task = input->text().trimmed();
     if (!task.isEmpty()) {
         list->addItem(task);
         input->clear();
     }
}

void MainWindow::removeTask() {
     QList<QListWidgetItem *> items = list->selectedItems();
     for (auto item : qAsConst(items)) {
          delete list->takeItem(list->row(item));
     }
}

MainWindow::~MainWindow() {
    delete centralWidget;
    delete layout;

    delete input;
    delete list;
    delete addButton;
    delete removeButton;
}
