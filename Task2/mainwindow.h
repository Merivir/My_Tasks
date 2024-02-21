#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void buttonHandler();

public:
    int count;

private:
    QVBoxLayout* layout;
    QLabel* label;
    QPushButton* button;
};

#endif // MAINWINDOW_H
