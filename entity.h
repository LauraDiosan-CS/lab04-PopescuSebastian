#pragma once
class Product
{
private:
	char* name;
public:
	Product();
	Product(char* name);
	Product(const Product& e);
	char* getName();
	void setName(char* newName);
	Product& operator = (const Product& e);
	bool operator == (const Product& e);
	~Product();
};

