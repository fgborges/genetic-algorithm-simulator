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
#ifndef OBJECT_H
#define OBJECT_H
#include<QPoint>
#include<QLine>
class Object{
	public:
		Object(int,int);
		Object(const QPoint&);
		Object(const QPoint&,const QPoint&);
		Object(const QLine&);
		Object();
		void moveTo(const QPoint&);
		void moveTo(int,int);
		void moveTo(const QPoint&,const QPoint&);
		void setPoint(const QPoint&);
		void setPoint(int,int);
		void setLine(const QPoint&,const QPoint&);
		QPoint p() const;
		QLine l() const;
		QPoint& rp();
		QLine& rl();
		int ObjNum()const;
	private:
		QPoint point;
		QLine line;
		int ObjectNumber;
};
#endif
