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
#ifndef SIGNAL_HPP
#define SIGNAL_HPP
#include"Object.hpp"
#include<QPoint>
#include<QVector>

class Signal : public Object{
	public:
		Signal(const QPoint&);
		Signal(int,int);
		Signal();
		bool sig(int);
	private:
		bool signal_pattern[8];
};
#endif
