#pragma once
#include "entity.h"
#include "date.h"
#include "repo.h"
class Controller {
private:
	Repo repo_list;
public:
	Controller();
	Controller(const Repo&);
	void setRepo(const Repo&);
	date getDateByName(char*);
	float getPriceByName(char*);
	bool addProduct(char*,date,float);
	bool updateProduct(char*, date, float);
	bool deleteProduct(char*);
	Product* getAll();
	int getSize();
	Product getElem(int);
	~Controller();
};