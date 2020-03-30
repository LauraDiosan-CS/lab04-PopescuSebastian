#include "run.h"
#include "entity.h"
#include "date.h"
#include "repo.h"
#include "Controller.h"
#include "Undo.h"
#include "Redo.h"
#include "read.h"
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
void menu() {
	std::cout <<"Menu:\n";
	std::cout << "0 : EXIT\n";
	std::cout << "1 : Add\n";
	std::cout << "2 : Print\n";
	std::cout << "3 : Update\n";
	std::cout << "4 : Delete\n";
	std::cout << "5 : Print all the products above a specific price\n";
	std::cout << "6 : Make products 10% cheaper that are in stock longer than a specific date\n";
	std::cout << "7 : Get rid of all COVID-19 infested products\n";
	std::cout << "8 : Undo\n";
	std::cout << "9 : Redo\n";
}

void UI::addProduct() {
	char* name;
	date d;
	float price;
	bool succes;
	name = read_name();
	d = read_date();
	price = read_price();
	succes = this->ctrl.addProduct(name, d, price);
	if (succes) {
		std::cout << "Product added succesfully in stock\n";
		this->undos.addEntityUndo(name, d, price, 1);
	}
	else
		std::cout << "Product failed to be added\n";
}

void UI::printAllProducts() {
	int size_list;
	size_list = this->ctrl.getSize();
	if (size_list == 0)
		std::cout << "No products are in stock!\n";
	for (int i = 0; i < size_list; i++) {
		Product elem = this->ctrl.getElem(i);
		std::cout << "Product #" << i + 1 << ":\n";
		std::cout <<"Has the name: "<< elem.getName() << ", stock enter date: " << elem.getStock_refill() << " and price: " << elem.getPrice() << "\n";
	}
}

void UI::updateProduct() {
	char* name_to_update;
	date d, d_undo;
	float price, price_undo;
	bool succes;
	name_to_update = read_name();
	d = read_date();
	price = read_price();
	d_undo = this->ctrl.getDateByName(name_to_update);
	price_undo = this->ctrl.getPriceByName(name_to_update);
	succes = this->ctrl.updateProduct(name_to_update, d, price);
	if (succes) {
		std::cout << "Product updated succesfully in stock\n";
		this->undos.addEntityUndo(name_to_update, d_undo, price_undo, 3);
	}
	else
		std::cout << "Product doesn't exist in stock\n";
}

void UI::deleteProduct() {
	char* name_to_delete;
	bool succes;
	date d_undo;
	float price_undo;
	name_to_delete = read_name();
	d_undo = this->ctrl.getDateByName(name_to_delete);
	price_undo = this->ctrl.getPriceByName(name_to_delete);
	succes = this->ctrl.deleteProduct(name_to_delete);
	if (succes) {
		std::cout << "The product was thrown away\n";
		this->undos.addEntityUndo(name_to_delete, d_undo, price_undo, 4);
	}
	else
		std::cout << "Product doesn't exist in stock\n";
}

void UI::printAllElemAbovePrice() {
	int size_list;
	size_list = this->ctrl.getSize();
	float price;
	price = read_price();
	for (int i = 0; i < size_list; i++) {
		Product elem = this->ctrl.getElem(i);
		if (elem.getPrice() > price) {
			std::cout << "Product #" << i + 1 << ":\n";
			std::cout << "Has the name: " << elem.getName() << ", stock enter date: " << elem.getStock_refill() << " and price: " << elem.getPrice() << "\n";
		}
		else
			std::cout << "No products above the treshhold\n";
	}
}

void UI::reducePricesBeforeDate() {
	int size_list;
	date d;
	d = read_date();
	size_list = this->ctrl.getSize();
	for (int i = 0; i < size_list; i++) {
		Product elem = this->ctrl.getElem(i);
		if (elem.getStock_refill() < d) {
			float price = elem.getPrice()*0.9, price_undo = elem.getPrice();
			this->undos.addEntityUndo(elem.getName(), d, price_undo, 6);
			this->ctrl.updateProduct(elem.getName(), elem.getStock_refill(), price);
		}
	}
}

void UI::elimCoronaInfested() {
	int size_list, coronaChance, contor = 0;
	size_list = this->ctrl.getSize();
	srand(time(NULL));
	coronaChance = rand();
	for (int i = 0; i < size_list; i++) {
		srand(time(NULL));
		coronaChance = rand();
		if (coronaChance % 2 == 1) {
			Product elem = this->ctrl.getElem(i);
			this->ctrl.deleteProduct(elem.getName());
			contor++;
		}
	}
	std::cout << "Number of SARS-COV-2 infestated products eliminated: " << contor << "\n";
}

void UI::undo() {
	int size_list, i;
	size_list = this->undos.getSize();
	if (size_list == 0)
		std::cout << "No operations to undo!\n";
	else {
		i = size_list - 1;
		Product elem = this->undos.getElem(i);
		int op = this->undos.getOp(i);
		if (op == 1) {
			this->redos.addEntityRedo(elem.getName(),elem.getStock_refill(),elem.getPrice(),4);
			this->ctrl.deleteProduct(elem.getName());
		}
		if (op == 3) {
			date d_redo = this->ctrl.getDateByName(elem.getName());
			float price_redo = this->ctrl.getPriceByName(elem.getName());
			this->redos.addEntityRedo(elem.getName(), d_redo, price_redo, 3);
			this->ctrl.updateProduct(elem.getName(), elem.getStock_refill(), elem.getPrice());
		}
		if (op == 4) {
			this->redos.addEntityRedo(elem.getName(), elem.getStock_refill(), elem.getPrice(), 1);
			this->ctrl.addProduct(elem.getName(), elem.getStock_refill(), elem.getPrice());
		}
		if (op == 6) {
			int size_list_ctrl;
			size_list_ctrl = this->ctrl.getSize();
			for (int i = 0; i < size_list_ctrl; i++) {
				Product element = this->ctrl.getElem(i);
				if (element.getStock_refill() <= elem.getStock_refill()) {
					this->redos.addEntityRedo(element.getName(), element.getStock_refill(), element.getPrice(),6);
					this->ctrl.updateProduct(element.getName(), element.getStock_refill(), elem.getPrice());
				}
			}
		}	
		this->undos.setSizeMinusOne();
	}
}

void UI::redo() {
	int size_list, i;
	size_list = this->redos.getSize();
	if (size_list == 0)
		std::cout << "No operations to Redo!\n";
	else {
		i = size_list - 1;
		Product elem = this->redos.getElem(i);
		int op = this->redos.getOp(i);
		if (op == 1) {
			this->undos.addEntityUndo(elem.getName(), elem.getStock_refill(), elem.getPrice(), 4);
			this->ctrl.deleteProduct(elem.getName());
		}
		if (op == 3) {
			date d = this->ctrl.getDateByName(elem.getName());
			float price = this->ctrl.getPriceByName(elem.getName());
			this->undos.addEntityUndo(elem.getName(), d, price, 3);
			this->ctrl.updateProduct(elem.getName(), elem.getStock_refill(), elem.getPrice());
		}
		if (op == 4) {
			this->undos.addEntityUndo(elem.getName(), elem.getStock_refill(), elem.getPrice(), 1);
			this->ctrl.addProduct(elem.getName(), elem.getStock_refill(), elem.getPrice());
		}
		if (op == 6) {
			int size_list_ctrl;
			size_list_ctrl = this->ctrl.getSize();
			for (int i = 0; i < size_list_ctrl; i++) {
				Product element = this->ctrl.getElem(i);
				if (element.getStock_refill() <= elem.getStock_refill()) {
					this->undos.addEntityUndo(element.getName(), element.getStock_refill(), element.getPrice(), 6);
					this->ctrl.updateProduct(element.getName(), element.getStock_refill(), elem.getPrice());
				}
			}
		}
		this->redos.setSizeMinusOne();
	}

}

void UI::run() {
	int cmd;
	menu();
	cmd = read_command();
	do {
		switch (cmd) {
		case 1:
			this->addProduct();
			break;
		case 2:
			this->printAllProducts();
			break;
		case 3:
			this->updateProduct();
			break;
		case 4:
			this->deleteProduct();
			break;
		case 5:
			this->printAllElemAbovePrice();
			break;
		case 6:
			this->reducePricesBeforeDate();
			break;
		case 7:
			this->elimCoronaInfested();
			break;
		case 8:
			this->undo();
			break;
		case 9:
			this->redo();
			break;
		}
		if (cmd != 0)
			cmd = read_command();
	} while (cmd != 0);
}