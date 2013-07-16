#include<QtGui>
#include"DrawMap.hpp"

int main(int argc,char** argv)
{
	QApplication app(argc,argv);
	DrawMap d;
	d.show();
	return app.exec();
}

