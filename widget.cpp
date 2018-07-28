#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //界面设计
    ui->setupUi(this);
    setWindowTitle("计算器");
    textedit->setGeometry(10,10,280,50);
    textedit->setReadOnly(true);
    textedit->setText(text);
    c->setGeometry(82,70,65,56);
    Backspace->setGeometry(154,70,65,56);
    division->setGeometry(226,70,65,56);
    seven->setGeometry(10,136,65,56);
    eight->setGeometry(82,136,65,56);
    nine->setGeometry(154,136,65,56);
    multiple->setGeometry(226,136,65,56);
    four->setGeometry(10,202,65,56);
    five->setGeometry(82,202,65,56);
    six->setGeometry(154,202,65,56);
    minus->setGeometry(226,202,65,56);
    one->setGeometry(10,268,65,56);
    two->setGeometry(82,268,65,56);
    three->setGeometry(154,268,65,56);
    plus->setGeometry(226,268,65,56);
    pom->setGeometry(10,334,65,56);
    zero->setGeometry(82,334,65,56);
    dot->setGeometry(154,334,65,56);
    equal->setGeometry(226,334,65,56);

    //储存计算
    connect(c,&QPushButton::clicked,this,clean);
    connect(one,&QPushButton::clicked,this,f_one);
    connect(two,&QPushButton::clicked,this,f_two);
    connect(three,&QPushButton::clicked,this,f_three);
    connect(four,&QPushButton::clicked,this,f_four);
    connect(five,&QPushButton::clicked,this,f_five);
    connect(six,&QPushButton::clicked,this,f_six);
    connect(seven,&QPushButton::clicked,this,f_seven);
    connect(eight,&QPushButton::clicked,this,f_eight);
    connect(nine,&QPushButton::clicked,this,f_nine);
    connect(zero,&QPushButton::clicked,this,f_zero);
    connect(dot,&QPushButton::clicked,this,f_dot);
    connect(pom,&QPushButton::clicked,this,f_pom);
    connect(plus,&QPushButton::clicked,this,f_plus);
    connect(minus,&QPushButton::clicked,this,f_minus);
    connect(multiple,&QPushButton::clicked,this,f_multiple);
    connect(division,&QPushButton::clicked,this,f_division);
    connect(equal,&QPushButton::clicked,this,f_equal);
    connect(Backspace,&QPushButton::clicked,this,f_backspace);
}

Widget::~Widget()
{
    delete ui;
    delete textedit;
    delete c;
    delete Backspace;
    delete division;
    delete seven;
    delete eight;
    delete nine;
    delete multiple;
    delete four;
    delete five;
    delete six;
    delete minus;
    delete one;
    delete two;
    delete three;
    delete plus;
    delete pom;
    delete zero;
    delete dot;
    delete equal;
}

void Widget::clean()
{
    text = "0";
    textedit->setText(text);
    state = true;
}

void Widget::f_one()
{
    if(state == false)
        clean();
    if(!repeating_zero())
        text += "1";
    else
    {
        text[text.length()-1] = '1';
    }
    textedit->setText(text);
}

void Widget::f_two()
{
    if(state == false)
        clean();
    if(!repeating_zero())
        text += "2";
    else
    {
        text[text.length()-1] = '2';
    }
    textedit->setText(text);
}

void Widget::f_three()
{
    if(state == false)
        clean();
    if(!repeating_zero())
        text += "3";
    else
    {
        text[text.length()-1] = '3';
    }
    textedit->setText(text);
}

void Widget::f_four()
{
    if(state == false)
        clean();
    if(!repeating_zero())
        text += "4";
    else
    {
        text[text.length()-1] = '4';
    }
    textedit->setText(text);
}

void Widget::f_five()
{
    if(state == false)
        clean();
    if(!repeating_zero())
        text += "5";
    else
    {
        text[text.length()-1] = '5';
    }
    textedit->setText(text);
}

void Widget::f_six()
{
    if(state == false)
        clean();
    if(!repeating_zero())
        text += "6";
    else
    {
        text[text.length()-1] = '6';
    }
    textedit->setText(text);
}


void Widget::f_seven()
{
    if(state == false)
        clean();
    if(!repeating_zero())
        text += "7";
    else
    {
        text[text.length()-1] = '7';
    }
    textedit->setText(text);
}

void Widget::f_eight()
{
    if(state == false)
        clean();
    if(!repeating_zero())
        text += "8";
    else
    {
        text[text.length()-1] = '8';
    }
    textedit->setText(text);
}

void Widget::f_nine()
{
    if(state == false)
        clean();
    if(!repeating_zero())
        text += "9";
    else
    {
        text[text.length()-1] = '9';
    }
    textedit->setText(text);
}

void Widget::f_zero()
{
    if(state == false)
        clean();
    if(!repeating_zero())
        text += "0";
    else
    {
        text[text.length()-1] = '0';
    }
    textedit->setText(text);
}

void Widget::f_dot()
{
    if(state == false)
        clean();
    for(int i = text.length() - 1 ; i >= 0 ; --i)
    {
        if(text[text.length() - 1] == '+' || text[text.length() - 1] == '-' || text[text.length() - 1] == '*' || text[text.length() - 1] == '/')
        {
            text += "0.";
            break;
        }
        if(text[i] == '.')
        {
            return;
        }
        if(i == 0 || text[i] == '+' || text[i] == '-' || text[i] == '*' || text[i] == '/')
        {
            text += ".";
            break;
        }
    }
    textedit->setText(text);
}

void Widget::f_pom()
{
    if(state == false)
        clean();
    if(text == "0")
    {
        text.insert(0,'-');
    }
    else
    {
        for(int i = text.length() - 1 ; i >= 0 ; --i)
        {
            if(!text[i].isNumber())
            {
                if(text[i] == '.')
                    continue;
                if(text[i] == '+')
                {
                    text[i] = '-';
                    break;
                }
                if(text[i] == '-')
                {
                    if(i == 0)
                        text = text.right(text.length()-1);
                    else if(text[i-1] == '*' || text[i-1] == '/')
                        text.remove(i,1);
                    else
                        text[i] = '+';
                    break;
                }
                if(text[i] == '*' || text[i] == '/')
                {
                    text.insert(i+1,'-');
                    break;
                }
            }
            else if(i == 0)
            {
                text.insert(0,'-');
            }
        }
    }
    textedit->setText(text);
}

void Widget::f_plus()
{
    if(state == false)
    {
        clean();
        text = result;
    }
    if(text[text.length()-1].isNumber())
        text += '+';
    else
        text[text.length()-1] = '+';
    textedit->setText(text);
}

void Widget::f_minus()
{
    if(state == false)
    {
        clean();
        text = result;
    }
    if(text[text.length()-1].isNumber())
        text += '-';
    else
        text[text.length()-1] = '-';
    textedit->setText(text);
}

void Widget::f_multiple()
{
    if(state == false)
    {
        clean();
        text = result;
    }
    if(text[text.length()-1].isNumber())
        text += '*';
    else
        text[text.length()-1] = '*';
    textedit->setText(text);
}

void Widget::f_division()
{
    if(state == false)
    {
        clean();
        text = result;
    }
    if(text[text.length()-1].isNumber())
        text += '/';
    else
        text[text.length()-1] = '/';
    textedit->setText(text);
}

void Widget::f_equal()
{
    if(state == false)
        return;
    if(!text[text.length()-1].isNumber())       //去除错误(尾部为符号)
        text.remove(text.length()-1,1);
    QString temp = text;
    //先按顺序计算乘除
    for(int i = 0 ; i < temp.length() ; ++i)
    {
        if(temp[i] == '*' || temp[i] == '/')
        {
            int j,k;
            for(j = i-1 ; j >= 0 ; --j)
            {
                if(j == 0)
                    break;
                if(temp[j] == '+' || temp[j] == '-')
                {
                    ++j;
                    break;
                }
            }
            for(k = i+1 ; k < temp.length() ; ++k)
            {
                if(k == temp.length()-1)
                    break;
                if(temp[i+1] == '-')
                    continue;
                if(temp[k] == '+' || temp[k] == '-' || temp[k] == '*' || temp[k] == '/')
                {
                    --k;
                    break;
                }
            }
            QString s_left = temp.mid(j,i-j);
            QString s_right = temp.mid(i+1,k-i);
            double left = s_left.toDouble();
            double right = s_right.toDouble();
            double res;
            if(temp[i] == '*')
                res = left * right;
            else
                res = left / right;
            QString s_res = QString::number(res,'g',15);
            temp.remove(j,k-j+1);
            temp.insert(j,s_res);
            debug(temp);    //去除多重符号
            i = 0;
        }
    }
    //然后计算加减
    for(int i = 0 ; i < temp.length() ; ++i)
    {
        if(temp[i] == '+' || temp[i] == '-')
        {
            int j,k;
            if(temp[i] == '-')
                if(i == 0)
                    continue;
            for(j = i-1 ; j >= 0 ; --j)
            {
                if(j == 0)
                    break;
                if(temp[j] == '+' || temp[j] == '-')
                {
                    if(temp[j] == '-')
                        if(j == 0)
                            break;
                    ++j;
                    break;
                }
            }
            for(k = i+1 ; k < temp.length() ; ++k)
            {
                if(k == temp.length()-1)
                    break;
                if(temp[k] == '+' || temp[k] == '-')
                {
                    --k;
                    break;
                }
            }
            QString s_left = temp.mid(j,i-j);
            QString s_right = temp.mid(i+1,k-i);
            double left = s_left.toDouble();
            double right = s_right.toDouble();
            double res;
            if(temp[i] == '+')
                res = left + right;
            else
                res = left - right;
            QString s_res = QString::number(res,'g',15);
            temp.remove(j,k-j+1);
            temp.insert(j,s_res);
            debug(temp);    //去除多重符号
            int num = 0;
            for(int i = 0 ; i < temp.length() ; ++i)
            {
                if(temp[i] == '+' || temp[i] == '-')
                    ++num;
            }
            if(num >= 2)
            {
                i = 0;
                num = 0;
                continue;
            }
            else
            {
                for(int i = 0 ; i < temp.length() ; ++i)
                {
                    if(temp[i] == '-')
                        if(i == 0)
                            state = false;
                }
                if(state == false)
                    break;
                else
                {
                    i = 0;
                    num = 0;
                    continue;
                }
            }
        }
    }
    result = temp;
    textedit->setText(text + '=' + temp);
    state = false;
}

void Widget::debug(QString &text)       //去除多重符号
{
    for(int i = 0 ; i < text.length() ; ++i)
    {
        if(text[i] == '-')
        {
            if(text[i+1] == '-')
                text.remove(i,1);
        }
        if(text[i] == '+')
        {
            if(text[i+1] == '-')
                text.remove(i,1);
        }
    }
}

bool Widget::repeating_zero()
{
    for(int i = text.length()-1 ; i >= 0 ; --i)
    {
        if(i == 0 && text[i] != '-')
        {
            if(text[i] == '0')
                return true;
            else
                return false;
        }
        if(text[i] == '+' || text[i] == '-' || text[i] == '*' || text[i] == '/')
        {
            if(i == text.length()-1)
                return false;
            else
                return true;
        }
        if(text[i] == '.')
            return false;
        if(text[i].isNumber() && text[i] != '0')
            return false;
        if(text[i] == '0')
            continue;
    }
}

void Widget::f_backspace()
{
    if(state == false)
        clean();
    else
    {
        if(text.length() == 1)
            clean();
        else
            text.remove(text.length()-1,1);
        textedit->setText(text);
    }
}
