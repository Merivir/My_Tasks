#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void checkMessage();

private:
    QPushButton* button;
    QLineEdit* line1;
    QLineEdit* line2;
    QLineEdit* line3;
    QVBoxLayout* layout;
};
#endif // MAINWINDOW_H
