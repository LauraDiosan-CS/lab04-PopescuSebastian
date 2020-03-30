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
	bool addEntity(Product e);
	bool updateEntity(Product e);
	bool deleteEntity(Product e);
	void update(Product e, int pos);
	Product getElemByName(char*);
	Product getElem(int pos);
	Product* getAll();
	void setSizeMinusOne();
	int getSize();
};

