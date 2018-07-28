#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QString>
#include <QVector>
#include <QMouseEvent>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void clean(void);
    void f_one();
    void f_two();
    void f_three();
    void f_four();
    void f_five();
    void f_six();
    void f_seven();
    void f_eight();
    void f_nine();
    void f_zero();
    void f_dot();
    void f_pom();
    void f_plus();
    void f_minus();
    void f_multiple();
    void f_division();
    void f_equal();
    void f_backspace();

    bool repeating_zero();      //检测数字前面是否以0开头

    void debug(QString &text);

private:
    Ui::Widget *ui;

    //控件
    QTextEdit *textedit = new QTextEdit(this);
    QPushButton *c = new QPushButton("C",this);
    QPushButton *Backspace = new QPushButton("Backspace",this);
    QPushButton *division = new QPushButton("÷",this);
    QPushButton *seven = new QPushButton("7",this);
    QPushButton *eight = new QPushButton("8",this);
    QPushButton *nine = new QPushButton("9",this);
    QPushButton *multiple = new QPushButton("×",this);
    QPushButton *four = new QPushButton("4",this);
    QPushButton *five = new QPushButton("5",this);
    QPushButton *six = new QPushButton("6",this);
    QPushButton *minus = new QPushButton("-",this);
    QPushButton *one = new QPushButton("1",this);
    QPushButton *two = new QPushButton("2",this);
    QPushButton *three = new QPushButton("3",this);
    QPushButton *plus = new QPushButton("+",this);
    QPushButton *pom = new QPushButton("±",this);
    QPushButton *zero = new QPushButton("0",this);
    QPushButton *dot = new QPushButton(".",this);
    QPushButton *equal = new QPushButton("=",this);

    //储存
    QString text = "0";
    bool state = true;
    QString result = "0";

protected:



};

#endif // WIDGET_H
