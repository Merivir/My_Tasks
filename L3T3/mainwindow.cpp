#include "mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , layout(new QGridLayout(this))
    , display(new QLineEdit())
    , value(0.0)
    , isPressed(false)
    , divByZero(false)
    , equal(false)
{
    setLayout(layout);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(20);
    layout->addWidget(display, 0, 0, 1, 4);

    for (int i = 1; i <= 9; ++i) {
        createButton(QString::number(i), &MainWindow::onDigitPressed);
    }
    createButton("0", &MainWindow::onDigitPressed);


    createButton("+", &MainWindow::onOperationPressed);
    createButton("-", &MainWindow::onOperationPressed);
    createButton("*", &MainWindow::onOperationPressed);
    createButton("/", &MainWindow::onOperationPressed);
    createButton("=", &MainWindow::onEqualsPressed);
    createButton("C", &MainWindow::onClearPressed);

    setStyleSheet("QPushButton { font-size: 18pt; } QLineEdit { font-size: 18pt; background: #f0f1f1; }");


}


MainWindow::~MainWindow() {
    for (int i = 0; i < buttons.size(); ++i) {
        layout->removeWidget(buttons[i]);
          delete buttons[i];
    }
    delete display;
    delete layout;

}

void MainWindow::createButton(const QString &text, void (MainWindow::*method)()) {
    QPushButton* button = new QPushButton(text, this);

    button->setObjectName(text);
    layout->addWidget(button);
    connect(button, &QPushButton::clicked, this, method);

    buttons.append(button);
}

void MainWindow::onDigitPressed() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString text = display->text();
    QChar symbol = text[0];

    if (equal) {
        display->clear();
        equal = false;
    }

    if (symbol == "+" || symbol == "-" || symbol == "*" || symbol == "/") {
        display->clear();
    }

    QString digitValue = button->text();

    display->setText(display->text() + digitValue);
}

void MainWindow::onOperationPressed() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString pressed = button->text();
    double acc = display->text().toDouble();
    display->clear();
    display->setText(pressed);

    if (!isPressed) {
        value = acc;
    } else {
        execution(acc, operation);
    }

    operation = pressed;
    isPressed = true;
}

void MainWindow::onEqualsPressed() {
    double displayValue = display->text().toDouble();
    equal = true;

    execution(displayValue, operation);
    isPressed = false;

    if (divByZero) {
        divByZero = false;
        return;
    }

    display->setText(QString::number(value, 'f', 2));
    operation.clear();

}


void MainWindow::execution(double displayValue, const QString& op) {
    if (op == "+") {
        value += displayValue;
    } else if (op == "-") {
        value -= displayValue;
    } else if (op == "*") {
        value *= displayValue;
    } else if (op == "/") {
        if (displayValue == 0.0) {
            display->setText("Error");
            equal = true;
            divByZero = true;
            return;
        }
        value /= displayValue;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() >= Qt::Key_0 && event->key() <= Qt::Key_9) {
        int digit = event->key() - Qt::Key_0;
        QString digitText = QString::number(digit);
        foreach (QPushButton* button, this->findChildren<QPushButton*>()) {
            if (button->text() == digitText) {
                button->click();
                break;
            }
        }
    } else {
        switch (event->key()) {
            case Qt::Key_Plus:
                findChild<QPushButton*>("+")->click();
                break;
            case Qt::Key_Minus:
                findChild<QPushButton*>("-")->click();
                break;
            case Qt::Key_Asterisk:
                findChild<QPushButton*>("*")->click();
                break;
            case Qt::Key_Slash:
                findChild<QPushButton*>("/")->click();
                break;
            case Qt::Key_Enter:
                findChild<QPushButton*>("=")->click();
                break;
            case Qt::Key_Escape:
                findChild<QPushButton*>("C")->click();
                break;
            default:
                QWidget::keyPressEvent(event);
        }
    }
}

void MainWindow::onClearPressed() {
    display->clear();
    value = 0.0;
    operation.clear();
    isPressed = false;
}



