#include "Controller.h"
#include "entity.h"
#include "repo.h"
void Contr_add_elem(char* name, date d, float price, Repo list[]) {
	Product e(name, d, price);
	list->addEntity(e);
}

void Contr_upd_elem(char* name, date d, float price, Repo list[]) {
	Product e(name, d, price);
	list->updateEntity(e);
}

void Contr_del_elem(char* name, Repo list[]) {
	date d(0, 0, 0);
	Product e(name, d, 0);
	list->deleteEntity(e);
}