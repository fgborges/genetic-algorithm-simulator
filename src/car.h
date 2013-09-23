/****************************************
 *  Author: MackRick.
 *   Email: mack.sept.public@gmail.com.
 *    File: car.h.
 * Project: /home/mackrick/program/school/TMP.
 *  Coding: en_US.UTF-8.
 * Summary:
 * Last Change: 10-Sep-2013.
 ****************************************/
#pragma once
#include<QPointF>
#include<QVector>
#include<QRectF>
class Car
{
public:
    Car(const int id = 0,const QPointF& pos=QPoint(0,0));
    void moveTo(const QPointF& pos);

    void Add2Log(const int id);
    void back_Log();
    bool isLog(const int id)const;

    void set_diff(const QPointF& in_diff);
    const QPointF& get_diff()const;

    void set_dest(const QPointF& dest);
    const QPointF& get_dest()const;

    int get_road_id()const;
    const QPointF& get_pos()const;

    const QRectF& get_rect()const;
    void set_rect(const QRectF& rect);

    void set_speed(const qreal speed);
    qreal get_speed()const;
    void set_num(int);
    int get_num()const;
    void Clear_log();
    void log_pop_back();
    int number;
    bool signal_stop;
private:
    QVector<int> log;
    QPointF diff;
    QPointF pos;
    QPointF dest;
    qreal speed;
    QRectF rect;
    int num;
};
