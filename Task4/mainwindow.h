#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addTask();
    void removeTask();

private:
    QWidget *centralWidget;
    QVBoxLayout *layout;
    QLineEdit *input;
    QListWidget *list;
    QPushButton *addButton;
    QPushButton *removeButton;

};
#endif // MAINWINDOW_H
