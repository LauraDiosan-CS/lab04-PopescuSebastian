#pragma once
#include "entity.h"
#include "date.h"
class Undo
{
private:
	Product undos[20];
	int index;
	int operation[20];
public:
	Undo();
	void addEntityUndo(char*,date,float,int);
	Product getElem(int pos);
	int getOp(int pos);
	int getSize();
	void setSizeMinusOne();
	~Undo();
};

