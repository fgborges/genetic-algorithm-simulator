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

Last Change: 11-Jul-2013.
*/
#ifndef ROAD_H
#define ROAD_H
#include"Object.hpp"
#include<QPoint>
#include<QLine>
class Road : public Object {
	public:
		Road(const QPoint&,const QPoint&);
		Road(const QLine&);
		Road();
		bool online(const QPoint&)const;
};
#endif
