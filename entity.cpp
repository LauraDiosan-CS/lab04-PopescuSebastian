#include "entity.h"
#include <iostream>
#include <string.h>

Product::Product() {
	this->name = NULL;
	date d(0,0,0);
	this->stock_refill = d;
	this->price = 0;
}

Product::Product(char* name, date stock_refill, float price) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1 + strlen(name), name);
	this->stock_refill = stock_refill;
	this->price = price;
}

Product::Product(const Product& e) {
	this->name = new char[strlen(e.name) + 1];
	strcpy_s(this->name, 1 + strlen(e.name), e.name);
	this->stock_refill = e.stock_refill;
	this->price = e.price;
}

char* Product::getName() {
	return this->name;
}

date Product::getStock_refill() {
	return this->stock_refill;
}

float Product::getPrice() {
	return this->price;
}

void Product::setName(char* newName) {
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(newName) + 1];
	strcpy_s(this->name, strlen(newName) + 1, newName);
}

void Product::setStock_refill(date newDate) {
	this->stock_refill = newDate;
}

void Product::setPrice(float newPrice) {
	this->price = newPrice;
}

Product& Product::operator=(const Product& e) {
	this->setName(e.name);
	this->setStock_refill(e.stock_refill);
	this->setPrice(e.price);
	return *this;
}

bool Product:: operator==(const Product& s) {
	if (strcmp(this->name, s.name) == 0)
		if (this->stock_refill == s.stock_refill)
			if (this->price == s.price)
				return true;
			else
				return false;
		else
			return false;
	else
		return false;
}

Product::~Product() {
	if (this->name) {
		delete[] this->name;
		this->name = NULL;
	}
	if (this->stock_refill.getDay()) {
		date d(0, 0, 0);
		this->stock_refill = d;
	}
	if (this->price)
		this->price = 0;
}