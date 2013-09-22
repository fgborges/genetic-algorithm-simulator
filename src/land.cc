/****************************************
 *  Author: MackRick.
 *   Email: mack.sept.public@gmail.com.
 *    File: land.cc.
 * Project: /home/mackrick/program/school/TMP.
 *  Coding: en_US.UTF-8.
 * Summary:
 * Last Change: 10-Sep-2013.
 ****************************************/

#include "land.h"
#include<QFile>
#include<QIODevice>
#include<QDebug>
#include<QList>
#include<QTextStream>
#include<QPointF>
#include<QString>
#include<QStringList>
#include<QtGlobal>

int Land::get_random_id()const
{
    return road.keys().at(qrand()%road.size());
}
Land::Land(const QString& filename)
{

    QFile f(filename);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<<"error";
            return;
        }
    QTextStream in(&f);
    QString buf;
    QPointF tmp,tmp2;
    int key=1;
    while(!in.atEnd())
        {
            buf = in.readLine();
            qDebug()<<buf;
            QStringList list = buf.split(",");
            if(list.at(0)=="road")
                {
                    tmp.setX(list.at(1).toInt());
                    tmp.setY(list.at(2).toInt());
                    tmp2.setX(list.at(3).toInt());
                    tmp2.setY(list.at(4).toInt());
                    road.insert(key,QLineF(tmp,tmp2));
                    key++;
                }
            else if(list.at(0)=="signal")
                {
                    tmp.setX(list.at(1).toInt());
                    tmp.setY(list.at(2).toInt());
                    Signal s(tmp.x(),tmp.y());
                    signal.append(s);
                }
        }
}
