/*
 ___      ___       __         ______     _    _
|   \    /   |     /  \       / ____ \   | | /  /
| |\ \  / /| |    / /\ \     / /    \_\  | |/  /
| | \ \/ / | |   / /__\ \   | |      _   |    /  
| |  \__/  | |  / ______ \   \ \____/ /  | |\ \
|_|        |_| /_/      \_\   \______/   |_| \_\

Tokyou Tech High School of Science and Technology

grade :3
class :B
Number:22
Name  :Masaya Taniguchi
e-mail:mack.sept.public@gmail.com

Last Change: 13-Jul-2013.
*/
#ifndef DRAWMAP_HPP
#define DRAWMAP_HPP

#include<QtGui>
#include"Land.hpp"
#include"Road.hpp"
#include"Car.hpp"
#include"Navi.hpp"
#include"Normal.hpp"
#include<QString>
#include"defines.hpp"
class DrawMap : public QWidget{
	Q_OBJECT
	public:
		DrawMap(QWidget *parent=0);
		void Init(); //initiarazation of car
	public slots:
		void onTimer();
	protected:
		void paintEvent(QPaintEvent*);
	private:
		QTimer *timer;
		Land land;
		QVector<Car> car;
		Navi navi;
};
#endif
