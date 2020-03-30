#include "repo.h"
#include "Entity.h";
#include "string.h"
Repo::Repo() {
	this->index = 0;
}

Repo::~Repo() {
	this->index = 0;
}

Product Repo::getElem(int pos) {
	return this->entities[pos];
}

Product Repo::getElemByName(char* name) {
	for (int i = 0; i < this->index; i++) {
		if (strcmp(name, this->entities[i].getName()) == 0) {
			return this->entities[i];
		}
	}
}

bool Repo::addEntity(Product e) {
	this->entities[this->index++] = e;
	return 1;
}

Product* Repo::getAll() {
	return this->entities;
}

void Repo::setSizeMinusOne() {
	this->index--;
}

int Repo::getSize() {
	return this->index;
}

void Repo::update(Product e, int pos) {
	this->entities[pos] = e;
}

bool Repo::updateEntity(Product e){
	bool found = false;
	for (int i = 0; i < this->index; i++) {
		if (strcmp(e.getName(), this->entities[i].getName()) == 0) {
			this->entities[i] = e;
			found = true;
		}
	}
	return found;
}

bool Repo::deleteEntity(Product e) {
	bool found = false;
	for (int i = 0; i < this->index; i++) {
		if (strcmp(e.getName(), this->entities[i].getName()) == 0) {
			for (int j = i; j < this->index - 1; j++) {
				this->entities[j] = this->entities[j + 1];
			}
			this->index--;
			found = true;
		}
	}
	return found;
}