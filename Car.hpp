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

Last Change: 16-Jul-2013.
*/
#ifndef CAR_H
#define CAR_H
#include"Object.hpp"
#include<QPoint>
class Car : public Object {
	public:
		Car(int,int,const QPoint&);
		Car(const QPoint&,const QPoint&);
		Car();
		void set_dX(int);
		void set_dY(int);
		void setD(const QPoint&);
		void set_dest(const QPoint&);
		void move();
		QPoint dest()const;
		bool first()const;
		void hasObjNum(int);
		void set_maindest(const QPoint&);
		QPoint maindest()const;
		int R_ObjNum()const;

		QVector<QPoint> log;
		bool sbmod;
	private:
		QPoint d;
		QPoint destination;
		int RoadObjectNumber;
		QPoint main_destination;
};
#endif
