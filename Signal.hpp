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

Last Change: 17-Jul-2013.
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
		void AppendPattern(QVector<int>);
		bool getSignal(long long int,int) const;
		QVector< QVector<int> > R_ObjNum;
};
#endif
