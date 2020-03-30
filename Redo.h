#pragma once
#include "entity.h"
#include "date.h"
class Redo
{
private:
	Product redos[20];
	int index;
	int operation[20];
public:
	Redo();
	void addEntityRedo(char*, date, float, int);
	Product getElem(int pos);
	int getOp(int pos);
	int getSize();
	void setSizeMinusOne();
	~Redo();
};

