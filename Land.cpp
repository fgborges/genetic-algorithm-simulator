#include "Land.hpp"
#include<QtGui>
#include<QMessageBox>
#include<QString>
#include<QDebug>
#include<QFile>
#include<QTextStream>
#include<QIODevice>
#include<QPoint>
#include<QLine>
#include "Road.hpp"
Land::Land(const QString& filename):str(filename)
{
	load();
}
void Land::load()
{
	QFile f(str);
	if(!f.open(QIODevice::ReadOnly | QIODevice::Text)){
		qDebug()<<"error";
		return;
	}
	QTextStream in(&f);
	QString buf;
	QPoint tmp,tmp2;
	while(!in.atEnd()){
		Road r;
		buf = in.readLine();
		qDebug()<<buf;
		QStringList list = buf.split(",");
		if(list.at(0)=="road"){
			tmp.setX(list.at(1).toInt());
			tmp.setY(list.at(2).toInt());
			tmp2.setX(list.at(3).toInt());
			tmp2.setY(list.at(4).toInt());
			r.setLine(tmp,tmp2);
			road.append(r);
		}else if(list.at(0)=="signal"){
			//None
		}
	}
}
