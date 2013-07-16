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
#ifndef NAVI_HPP
#define NAVI_HPP
#include "Land.hpp"
#include "Car.hpp"
#include "Normal.hpp"
#include <QPoint>
class Navi {
	public:
		Navi(Land*);
		void CarMove(QVector<Car>::iterator);
	private:
		const Land *land_ptr;
};
#endif
