/****************************************
 *  Author: MackRick.
 *   Email: mack.sept.public@outlook.jp.
 *    File: method.cc.
 * Project: /home/mackrick/beta1/src/GA.
 *  Coding: en_US.UTF-8.
 * Summary:
 * Last Change: 12-Sep-2013.
 ****************************************/
#include"population.h"
#include <QDebug>
void Population::method()
{
	qDebug()<<"CALL SELECT()";
	this->Select();
	qDebug()<<"CALL CLOSSOVER()";
	this->ClossOver();
	qDebug()<<"CALL MUTATE()";
	this->Mutate();
}
