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

void Repo::addEntity(Product e) {
	this->entities[this->index++] = e;
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

void Repo::updateEntity(Product e){
	for (int i = 0; i < this->index; i++) {
		if (strcmp(e.getName(), this->entities[i].getName()) == 0) {
			this->entities[i] = e;
		}
	}
}

void Repo::deleteEntity(Product e) {
	for (int i = 0; i < this->index; i++) {
		if (strcmp(e.getName(), this->entities[i].getName()) == 0) {
			for (int j = i; j < this->index - 1; j++) {
				this->entities[j] = this->entities[j + 1];
			}
			this->index--;
		}
	}
}