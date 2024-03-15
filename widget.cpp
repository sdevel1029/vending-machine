#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


int coffeePrice = 100;
int teaPrice = 200;
int tangPrice = 300;

void Widget::updateButtonStatus()
{
    ui->pbCoffee->setEnabled(money >= coffeePrice);
    ui->pbTea->setEnabled(money >= teaPrice);
    ui->pbTang->setEnabled(money >= tangPrice);
    ui->pbReset->setEnabled(money > 0);
}


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    updateButtonStatus();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
      updateButtonStatus();
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
 changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
   changeMoney(100);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbCoin500_clicked()
{
      changeMoney(500);
}


void Widget::on_pbTang_clicked()
{
     changeMoney(-300);
}


void Widget::on_pbReset_clicked()
{
       int change500 = money / 500;
       int remainingMoney = money % 500;

       int change100 = remainingMoney / 100;
       remainingMoney %= 100;

       int change50 = remainingMoney / 50;
       remainingMoney %= 50;

       int change10 = remainingMoney / 10;

       QString changeMessage = QString("500원 동전: %1개\n100원 동전: %2개\n50원 동전: %3개\n10원 동전: %4개")
               .arg(change500).arg(change100).arg(change50).arg(change10);

       QMessageBox mb;
       mb.information(nullptr, "잔돈 알림", changeMessage);

       money = 0;
       ui->lcdNumber->display(money);
       updateButtonStatus();
}

