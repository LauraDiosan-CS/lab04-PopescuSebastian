#pragma once
#include "date.h"

class Product
{
private:
	char* name;
	date stock_refill;
	float price;
public:
	Product();
	Product(char* name, date stock_refill, float price);
	Product(const Product& e);
	char* getName();
	date getStock_refill();
	float getPrice();
	void setName(char* newName);
	void setStock_refill(date newDate);
	void setPrice(float newPrice);
	Product& operator = (const Product& e);
	bool operator == (const Product& e);
	~Product();
};

