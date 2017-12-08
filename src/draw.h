/****************************************
 *  Author: MackRick.
 *   Email: mack.sept.public@outlook.jp.
 *    File: draw.h.
 * Project: /home/mackrick/beta1/src.
 *  Coding: en_US.UTF-8.
 * Summary:
 * Last Change: 12-Sep-2013.
 ****************************************/
#pragma once
#include "src/land.h"
#include "src/car.h"
#include<QWidget>
#include<QVector>
#include"src/GA/population.h"
#include "src/GA/individual.h"
class Draw : public QWidget
{
    Q_OBJECT
public:
    Draw(QString filename = "data.cvs",
         int car_number = 10,
         QString img = "none",
         QWidget* parent = 0 );
signals:
    void evalChanged(int);
public slots:
    void onTimer();
    void reset();
    void onTimer2();
    void change_speed(int speed);
protected:
    void paintEvent(QPaintEvent*);
private:
    //CarMoviAction
    void SetDiff(Car& car,const QLineF& road);
    void SetNextRoad(Car& car);
    void smartAssist(Car& car);
    void CheckSignal(Car& car,long long int l_line);
    bool Reach(const Car& car,const QLineF& road)const;
    //Evaluate
    int Evaluate();
    //Initialized funciton;
    void InitCar();
    void InitSignal(Individual& indiv);
    //count Function
    int Count_car(int key);
    //menber
    QTimer *timer,*timer2;
    Land land;
    QVector<QLineF> map;
    const QString img;
    QVector<Car> car;
    const int car_number;
    unsigned long long g_clock;
    Population *pop;
    int index;
    int RoadNum;
    int CAR_SIZE;
    int CarNum;
};

