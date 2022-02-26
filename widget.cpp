#include "widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
    this->setWindowTitle("Системы счисления");
    this->resize(450, 300);
    calculate();
    labelInterNum();
    lineForNumbers();
    resultSettings();
    initialSettings();
    radioButtons();
    pushButtons();
    buttonDelete();
    buttonExit();
    layoutSettings();
}

void Widget::calculate()
{
    calculation->setWindowTitle(" ");
    QPixmap pm = QPixmap(1, 1);
    pm.fill(QColor(0, 0, 0, 0));
    calculation->setWindowIcon(QIcon(pm));
    connect(calculationButton, &QPushButton::clicked,
        [=]() {
            if (dec->isChecked() && !calculation->isVisible()) {
                int x = (this->geometry().x() + this->frameGeometry().width());
                int y = (this->geometry().y());
                calculation->setGeometry(x, y, 260, this->height());
                calculateFirstColumn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                QFont times("Times", 14);
                calculateFirstColumn->setFont(times);
                calculateSecondColumn->setFont(times);
                calculateSecondColumn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                calculateResult->setFixedHeight(30);
                calculateResult->setFont(times);
                calculateResult->setText(outputOfResults->text());
                calculateResult->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                calculation->show();
                this->activateWindow();
            } else {
                calculation->close();
            }
        });
    if (!calculation->isVisible()) {
        calculateFirstColumn->setText(0);
    }
}

void Widget::labelInterNum()
{
    textInsertNum->setGeometry(10, 10, 300, 20);
    textInsertNum->setFont(QFont("Times", 14));
}

void Widget::lineForNumbers()
{
    inputField->setValidator(intValidForField);
    inputField->setGeometry(10, 50, 300, 40);
    inputField->setFont(QFont("Times", 16));
    inputField->setStyleSheet("border: 1px solid gray;; border-radius: 2px;");
}

void Widget::resultSettings()
{
    outputOfResults->setFont(QFont("Times", 26));
    outputOfResults->setNum(0);
}

void Widget::initialSettings()
{
    dec->setChecked(true);
    connect(dec, &QRadioButton::clicked,
        [=]() {
            inputField->setText(0);
            inputField->setFocus();
            inputField->setValidator(intValid);
            calculationButton->setEnabled(true);
        });
}

void Widget::radioButtons()
{
    connect(bin, &QRadioButton::clicked,
        [=]() {
            calculation->close();
            inputField->setText(0);
            inputField->setFocus();
            inputField->setValidator(binValid);
            calculationButton->setEnabled(false);
        });
    connect(oct, &QRadioButton::clicked,
        [=]() {
            calculation->close();
            inputField->setText(0);
            inputField->setFocus();
            inputField->setValidator(octValid);
            calculationButton->setEnabled(false);
        });
    connect(hex, &QRadioButton::clicked,
        [=]() {
            calculation->close();
            inputField->setText(0);
            inputField->setFocus();
            inputField->setValidator(hexValid);
            calculationButton->setEnabled(false);
        });
}

void Widget::pushButtons()
{
    buttonStyle();
    buttonHex();
    buttonOct();
    buttonBin();
    buttonDec();
}

void Widget::buttonHex()
{
    butHex->setGeometry(10, 80, 50, 50);
    butHex->setStyleSheet(butStyle);
    connect(butHex, &QPushButton::clicked,
        [=]() {
            if (dec->isChecked()) {
                outputOfResults->setText(
                    inputField->text().number(
                                          inputField->text().toInt(), 16).toUpper());
            }
            if (hex->isChecked()) {
                int x = inputField->text().toInt(0, 16);
                QString o16to16;
                o16to16 = QString("%1").arg(x, 0, 16).toUpper();
                outputOfResults->setText(o16to16);
            }
            if (bin->isChecked()) {
                int x = inputField->text().toInt(0, 2);
                QString o2to16;
                o2to16 = QString("%1").arg(x, 0, 16).toUpper();
                outputOfResults->setText(o2to16);
            }
            if (oct->isChecked()) {
                int x = inputField->text().toInt(0, 8);
                QString o8to16;
                o8to16 = QString("%1").arg(x, 0, 16).toUpper();
                outputOfResults->setText(o8to16);
            }
            int x = inputField->text().toInt(0, 10);
            calculateFirstColumn->clear();
            calculateSecondColumn->clear();
            calculateResult->setText(outputOfResults->text());
            while (x != 0) {
                calculateFirstColumn->append(QString::number(x) + "|16");
                switch (x % 16) {
                case 10:
                    calculateSecondColumn->append("A");
                    break;
                case 11:
                    calculateSecondColumn->append("B");
                    break;
                case 12:
                    calculateSecondColumn->append("C");
                    break;
                case 13:
                    calculateSecondColumn->append("D");
                    break;
                case 14:
                    calculateSecondColumn->append("E");
                    break;
                case 15:
                    calculateSecondColumn->append("F");
                    break;
                default:
                    calculateSecondColumn->append(QString::number(x % 16));
                }
                x /= 16;
            }
        });
}

void Widget::buttonOct()
{
    butOct->setStyleSheet(butStyle);
    connect(butOct, &QPushButton::clicked,
        [=]() {
            if (dec->isChecked()) {
                outputOfResults->setText(
                    inputField->text().number(
                        inputField->text().toInt(), 8));
            }
            if (oct->isChecked()) {
                outputOfResults->setText(
                    inputField->text().number(
                                          inputField->text().toInt(0, 10)).toUpper());
            }
            if (bin->isChecked()) {
                int x = inputField->text().toInt(0, 2);
                QString o2to8;
                o2to8 = QString("%1").arg(x, 0, 8);
                outputOfResults->setText(o2to8);
            }
            if (hex->isChecked()) {
                int x = inputField->text().toInt(0, 16);
                QString o16to8;
                o16to8 = QString("%1").arg(x, 0, 8);
                outputOfResults->setText(o16to8);
            }
            int x = inputField->text().toInt(0, 10);
            calculateFirstColumn->clear();
            calculateSecondColumn->clear();
            calculateResult->setText(outputOfResults->text());
            while (x != 0) {
                calculateFirstColumn->append(QString::number(x) + "|8");
                calculateSecondColumn->append(QString::number(x % 8));
                x /= 8;
            }
        });
}

void Widget::buttonBin()
{
    butBin->setStyleSheet(butStyle);
    connect(butBin, &QPushButton::clicked,
        [=]() {
            if (dec->isChecked()) {
                outputOfResults->setText(
                    inputField->text().number(
                        inputField->text().toInt(), 2));
            }
            if (bin->isChecked()) {
                outputOfResults->setText(
                    inputField->text().number(
                        inputField->text().toInt(0, 10)));
            }
            if (oct->isChecked()) {
                int x = inputField->text().toInt(0, 8);
                QString o8to2;
                o8to2 = QString("%1").arg(x, 0, 2);
                outputOfResults->setText(o8to2);
            }
            if (hex->isChecked()) {
                int x = inputField->text().toInt(0, 16);
                QString o16to2;
                o16to2 = QString("%1").arg(x, 0, 2);
                outputOfResults->setText(o16to2);
            }
            int x = inputField->text().toInt(0, 10);
            calculateFirstColumn->clear();
            calculateSecondColumn->clear();
            calculateResult->setText(outputOfResults->text());
            while (x != 0) {
                calculateFirstColumn->append(QString::number(x) + "|2");
                calculateSecondColumn->append(QString::number(x % 2));
                x /= 2;
            }
        });
}

void Widget::buttonDec()
{
    butDec->setStyleSheet(butStyle);
    connect(butDec, &QPushButton::clicked,
        [=]() {
            if (dec->isChecked()) {
                outputOfResults->setText(
                    inputField->text().number(
                        inputField->text().toInt(), 10));
            }
            if (bin->isChecked()) {
                outputOfResults->setText(
                    inputField->text().number(
                        inputField->text().toInt(0, 2)));
            }
            if (oct->isChecked()) {
                outputOfResults->setText(
                    inputField->text().number(
                        inputField->text().toInt(0, 8)));
            }
            if (hex->isChecked()) {
                outputOfResults->setText(
                    inputField->text().number(
                                          inputField->text().toInt(0, 16)).toUpper());
            }
            calculateFirstColumn->clear();
            calculateSecondColumn->clear();
            calculateResult->setText(outputOfResults->text());
        });
}

void Widget::buttonDelete()
{
    clearButton->setStyleSheet(butStyle);
    clearButton->setFixedHeight(29);
    connect(clearButton, &QPushButton::clicked, [=]() {
        inputField->setText(0);
    });
}

void Widget::buttonExit()
{
    exitButton->setStyleSheet(butStyle);
    exitButton->setGeometry(10, 90, 50, 20);
    connect(exitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void Widget::layoutSettings()
{
    radioButtonField->addWidget(dec, 0, 0);
    radioButtonField->addWidget(bin, 1, 0);
    radioButtonField->addWidget(oct, 2, 0);
    radioButtonField->addWidget(hex, 3, 0);
    radioButtonField->addWidget(calculationButton, 0, 1);
    entryField->addWidget(inputField, 3);
    entryField->addWidget(clearButton, 0);
    buttonsField->addWidget(butDec, 0, 3);
    buttonsField->addWidget(butBin, 0, 0);
    buttonsField->addWidget(butOct, 0, 1);
    buttonsField->addWidget(butHex, 0, 2);
    generalField->addWidget(outputOfResults);
    generalField->addWidget(textInsertNum);
    generalField->addLayout(radioButtonField);
    generalField->addLayout(entryField);
    generalField->addLayout(buttonsField);
    generalField->addWidget(exitButton);
    setLayout(generalField);
    inputField->setFocus();
    calculateColumnsField->addWidget(calculateFirstColumn, 0, 0);
    calculateColumnsField->addWidget(calculateSecondColumn, 0, 1);
    calculateField->addLayout(calculateColumnsField);
    calculateField->addWidget(calculateResult);
    calculation->setLayout(calculateField);
}

void Widget::buttonStyle()
{
    butStyle = "QPushButton{color: #333;border: 1px solid #555;border-radius: 2px;border-style: outset;"
               "background-color: rgb(208, 208, 201);padding: 5px;}"
               "QPushButton:hover {background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,"
               "radius: 1.35, stop: 0 #fff, stop: 1 #bbb);}"
               "QPushButton:pressed {border-style: inset;"
               "background: qradialgradient(cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,"
               "radius: 1.35, stop: 0 #fff, stop: 1 #ddd);}";
    calculationButton->setStyleSheet(butStyle);
}

void Widget::closeEvent(QCloseEvent* event)
{
    event->ignore();
    calculation->close();
    event->accept();
}

Widget::~Widget()
{
    delete calculateFirstColumn;
    delete calculateSecondColumn;
    delete calculateResult;
    delete calculateColumnsField;
    delete calculateField;
    delete calculation;
    delete outputOfResults;
    delete bin;
    delete oct;
    delete dec;
    delete hex;
    delete textInsertNum;
    delete butBin;
    delete butOct;
    delete butDec;
    delete butHex;
    delete calculationButton;
    delete clearButton;
    delete exitButton;
    delete buttonsField;
    delete entryField;
    delete radioButtonField;
    delete generalField;
    delete intValid;
    delete intValidForField;
    delete binValid;
    delete octValid;
    delete hexValid;
    delete inputField;
}
