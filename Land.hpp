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

Last Change: 10-Jul-2013.
*/
#ifndef LAND_H
#define LAND_H

#include "Road.hpp"
#include<QString>
#include<QVector>
struct Land {
		Land(const QString&);
		void load();
		QString str;
		QVector<Road> road;
};
#endif
