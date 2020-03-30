#include "Controller.h"
#include "entity.h"
#include "repo.h"

Controller::Controller() {
}

Controller::Controller(const Repo& r) {
	repo_list = r;
}

void Controller::setRepo(const Repo& r) {
	repo_list = r;
}

bool Controller::addProduct(char* name, date d, float price) {
	Product p(name, d, price);
	bool succes;
	succes = repo_list.addEntity(p);
	return succes;
}

bool Controller::updateProduct(char* name, date d, float price) {
	Product p(name, d, price);
	bool succes;
	succes = repo_list.updateEntity(p);
	return succes;
}

bool Controller::deleteProduct(char* name) {
	date d(0, 0, 0);
	Product p(name, d, 0);
	bool succes;
	succes = repo_list.deleteEntity(p);
	return succes;
}

Product* Controller::getAll() {
	return repo_list.getAll();
}

int Controller::getSize() {
	return repo_list.getSize();
}

date Controller::getDateByName(char* name){
	Product p;
	p = repo_list.getElemByName(name);
	return p.getStock_refill();
}

float Controller::getPriceByName(char* name) {
	Product p;
	p = repo_list.getElemByName(name);
	return p.getPrice();
}

Product Controller::getElem(int index) {
	return repo_list.getElem(index);
}

Controller::~Controller() {}
