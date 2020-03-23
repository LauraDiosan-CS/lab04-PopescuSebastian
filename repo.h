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
	void updateEntity(Product e);
	void deleteEntity(Product e);
	void update(Product e, int pos);
	Product getElem(int pos);
	Product* getAll();
	void setSizeMinusOne();
	int getSize();
};

