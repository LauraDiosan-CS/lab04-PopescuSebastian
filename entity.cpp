#include "entity.h"
#include <iostream>
#include <string.h>

Product::Product() {
	this->name = NULL;
}

Product::Product(char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1 + strlen(name), name);
}

Product::Product(const Product& e) {
	this->name = new char[strlen(e.name) + 1];
	strcpy_s(this->name, 1 + strlen(e.name), e.name);
}

char* Product::getName() {
	return this->name;
}

void Product::setName(char* newName) {
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(newName) + 1];
	strcpy_s(this->name, strlen(newName) + 1, newName);
}

Product& Product::operator=(const Product& e) {
	this->setName(e.name);
	return *this;
}

bool Product:: operator==(const Product& s) {
	return strcmp(this->name, s.name) == 0;
}

Product::~Product() {
	if (this->name) {
		delete[] this->name;
		this->name = NULL;
	}
}