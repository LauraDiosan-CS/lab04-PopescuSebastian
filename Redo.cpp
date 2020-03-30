#include "Redo.h"
#include "entity.h"
#include "date.h"
Redo::Redo() {
	this->index = 0;
}

Redo::~Redo() {
	this->index = 0;
}

void Redo::addEntityRedo(char* name, date d, float price, int op) {
	Product p(name, d, price);
	this->operation[this->index] = op;
	this->redos[this->index++] = p;
}

int Redo::getSize() {
	return this->index;
}

Product Redo::getElem(int pos) {
	return this->redos[pos];
}

int Redo::getOp(int pos) {
	return this->operation[pos];
}

void Redo::setSizeMinusOne() {
	this->index--;
}