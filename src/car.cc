/****************************************
 *  Author: MackRick.
 *   Email: mack.sept.public@gmail.com.
 *    File: car.cc.
 * Project: /home/mackrick/program/school/TMP.
 *  Coding: en_US.UTF-8.
 * Summary:
 * Last Change: 10-Sep-2013.
 ****************************************/
#include "car.h"
#include<QPointF>
#include<QDebug>
#include<algorithm>

Car::Car(const int id,const QPointF& pos)
    :pos(pos),speed(2),rect(0,0,6,6)
{
    log.append(id);
    signal_stop=false;
}

void Car::moveTo(const QPointF& pos)
{
    this->pos = pos;
}

const QPointF& Car::get_pos()const
{
    return this->pos;
}

void Car::Add2Log(const int id)
{
    log.append(id);
}

bool Car::isLog(const int id)const
{
    return std::find(log.begin(),log.end(),id)!=log.end();
}

void Car::back_Log()
{
    log.pop_back();
}

void Car::set_diff(const QPointF& in_diff)
{
    this->diff=in_diff*this->speed;
}

const QPointF& Car::get_diff()const
{
    return this->diff;
}

void Car::set_dest(const QPointF& dest)
{
    this->dest = dest;
}

const QPointF& Car::get_dest()const
{
    return dest;
}

int Car::get_road_id()const
{
    return log.last();
}

void Car::Clear_log()
{
    log.clear();
}

const QRectF& Car::get_rect()const
{
    return this->rect;
}

void Car::set_rect(const QRectF& rect)
{
    this->rect = rect;
}

void Car::set_speed(const qreal speed)
{
    this->speed=speed;
}
qreal Car::get_speed()const
{
    return this->speed;
}
