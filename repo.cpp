#include "repo.h"
Repo::Repo() {
	this->index = 0;
}

Repo::~Repo() {
	this->index = 0;
}

Product Repo::getElem(int pos) {
	return this->entities[pos];
}

void Repo::addEntity(Product e) {
	this->entities[this->index++] = e;
}

Product* Repo::getAll() {
	return this->entities;
}

int Repo::getSize() {
	return this->index;
}