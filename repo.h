#pragma once
#include "entity.h"
class Repo
{
private:
	Product entities[10];
	int index;
public:
	Repo();
	~Repo();
	void addEntity(Product e);
	Product getElem(int pos);
	Product* getAll();
	int getSize();
};

