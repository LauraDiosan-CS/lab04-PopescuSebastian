#pragma once
#include "Controller.h"
#include "Undo.h"
#include "Redo.h"
class UI {
private:
	Controller ctrl;
	Undo undos;
	Redo redos;
	void addProduct();
	void printAllProducts();
	void updateProduct();
	void deleteProduct();
	void printAllElemAbovePrice();
	void reducePricesBeforeDate();
	void elimCoronaInfested();
	void undo();
	void redo();
public:
	void run();
};
void menu();
