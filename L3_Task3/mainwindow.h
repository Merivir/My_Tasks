#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
#include <QLineEdit>
#include <QKeyEvent>
#include <QtMath>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onDigitPressed();
    void onOperationPressed();
    void onEqualsPressed();
    void onClearPressed();

private:
    QGridLayout* layout;
    QLineEdit* display;

    QList<QPushButton*> buttons;

    double value;
    QString operation;
    bool isPressed;
    bool divByZero;
    bool equal;

    void keyPressEvent(QKeyEvent *event);
    void createButton(const QString &text, void (MainWindow::*method)());
    void execution(double displayValue, const QString& op);


};
#endif // MAINWINDOW_H
