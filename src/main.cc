/****************************************
 *  Author: MackRick.
 *   Email: mack.sept.public@gmail.com.
 *    File: main.cc.
 * Project: /home/mackrick/beta1/src.
 *  Coding: ja_JP.UTF-8.
 * Summary:
 * Last Change: 12-Sep-2013.
 ****************************************/

#include<QWidget>
#include"draw.h"
#include<QApplication>
#include<iostream>
#include<cstdlib>
#include<QPushButton>
#include<QDial>
#include<QLCDNumber>

int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    Draw* draw;
    QPushButton* resetButton = new QPushButton("reset");
    QDial* dial = new QDial();
    QLCDNumber* LCD=new QLCDNumber();
    if(argc==4)draw = new Draw(argv[1],atoi(argv[2]),argv[3]);
    else if(argc==3)draw = new Draw(argv[1],atoi(argv[2]));
    else if(argc==2)draw = new Draw(argv[1]);
    draw->show();
    QObject::connect(resetButton,SIGNAL(clicked()),draw,SLOT(reset()));
    QObject::connect(dial,SIGNAL(valueChanged(int)),draw,SLOT(change_speed(int)));
    QObject::connect(draw,SIGNAL(evalChanged(int)),LCD,SLOT(display(int)));
    resetButton->show();
    dial->show();
    LCD->show();
    return app.exec();
}
