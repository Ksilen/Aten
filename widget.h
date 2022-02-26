#ifndef WIDGET_H
#define WIDGET_H
#include <QApplication>
#include <QCloseEvent>
#include <QDoubleValidator>
#include <QFont>
#include <QGridLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget() override;

private:
    void calculate(); //окно для детального просчета
    void labelInterNum(); //надпись "Введите число"
    void lineForNumbers(); // linеEdit для ввода чисел
    void resultSettings(); //шрифт вывода результатов
    void initialSettings(); //начальные установки
    void radioButtons();
    void pushButtons(); //кнопочки для преревода в другую систему счисления
    void buttonBin();
    void buttonOct();
    void buttonDec();
    void buttonHex();
    void buttonDelete();
    void buttonExit();
    void layoutSettings();
    void buttonStyle();
    void closeEvent(QCloseEvent* event);
    QWidget* calculation = new QWidget; //окно для вывода детального просчета
    QLineEdit* inputField = new QLineEdit; //для ввода чисел
    QLabel* outputOfResults = new QLabel; //вывод результатов
    QRadioButton* bin = new QRadioButton("Двоичные");
    QRadioButton* oct = new QRadioButton("8-ные");
    QRadioButton* dec = new QRadioButton("Десятичные");
    QRadioButton* hex = new QRadioButton("16-ные");
    QPushButton* butBin = new QPushButton("В 2-ую");
    QPushButton* butOct = new QPushButton("В 8-ую");
    QPushButton* butDec = new QPushButton("В Десятичную");
    QPushButton* butHex = new QPushButton("В 16-ую");
    QPushButton* calculationButton = new QPushButton("Вычисления");
    QPushButton* clearButton = new QPushButton("Удалить");
    QPushButton* exitButton = new QPushButton("Выход");
    QTextEdit* calculateFirstColumn = new QTextEdit; //окна для вычислений
    QTextEdit* calculateSecondColumn = new QTextEdit;
    QLineEdit* calculateResult = new QLineEdit;
    QLabel* textInsertNum = new QLabel("Введите число:");
    QString butStyle;
    QGridLayout* buttonsField = new QGridLayout;
    QHBoxLayout* entryField = new QHBoxLayout;
    QGridLayout* radioButtonField = new QGridLayout;
    QVBoxLayout* generalField = new QVBoxLayout;
    QGridLayout* calculateColumnsField = new QGridLayout;
    QVBoxLayout* calculateField = new QVBoxLayout;
    QIntValidator* intValid = new QIntValidator(0, 100000, inputField);
    QIntValidator* intValidForField = new QIntValidator(0, 1000000, inputField);
    QRegularExpressionValidator* binValid = new QRegularExpressionValidator(QRegularExpression("[01]{1,20}"), inputField);
    QRegularExpressionValidator* octValid = new QRegularExpressionValidator(QRegularExpression("[0-7]{1,6}"), inputField);
    QRegularExpressionValidator* hexValid = new QRegularExpressionValidator(QRegularExpression("[0-9ABCDFabcdf]{1,5}"), inputField);
};
#endif // WIDGET_H
