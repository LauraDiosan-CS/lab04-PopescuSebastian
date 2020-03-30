#include "Undo.h"
#include "entity.h"
#include "date.h"
Undo::Undo(){
	this->index = 0;
}

Undo::~Undo() {
	this->index = 0;
}

void Undo::addEntityUndo(char* name,date d, float price, int op) {
	Product p(name,d,price);
	this->operation[this->index] = op;
	this->undos[this->index++] = p;
}

int Undo::getSize() {
	return this->index;
}

Product Undo::getElem(int pos) {
	return this->undos[pos];
}

int Undo::getOp(int pos) {
	return this->operation[pos];
}

void Undo::setSizeMinusOne() {
	this->index--;
}