#include "run.h"
#include "entity.h"
#include "date.h"
#include "repo.h"
#include "Controller.h"
#include <iostream>
void menu() {
	std::cout <<"Menu:\n";
	std::cout << "0 : EXIT\n";
	std::cout << "1 : Add\n";
	std::cout << "2 : Print\n";
	std::cout << "3 : Update\n";
	std::cout << "4 : Delete\n";
	std::cout << "5 : Print all the products under a specific price\n";
	std::cout << "6 : Make products 10% cheaper that are in stock longer than a specific date\n";
	std::cout << "7 : Get rid of all COVID-19 infested products\n";
}

int read_command() {
	int cmd;
	std::cout << "Command:"; std::cin >> cmd;
	return cmd;
}

char* read_name() {
	char* name = new char[20];
	std::cout << "Name:"; std::cin >> name;
	return name;
}

date read_date() {
	date d;
	int day, month, year;
	std::cout << "Day: "; std::cin >> day;
	std::cout << "Month: "; std::cin >> month;
	std::cout << "Year: "; std::cin >> year;
	d.setDay(day);
	d.setMonth(month);
	d.setYear(year);
	return d;
}

float read_price() {
	float p;
	std::cout << "Price:"; std::cin >> p;
	return p;
}

void run_program() {
	int cmd, size_list;
	float price;
	menu();
	cmd = read_command();
	Repo list[15];
	date d;
	do {
		switch (cmd) {
		case 1:
			char* name;
			name = read_name();
			d = read_date();
			price = read_price();
			Contr_add_elem(name, d, price, list);
			break;
		case 2:
			size_list = list->getSize();
			for (int i = 0; i < size_list; i++) {
				Product elem = list->getElem(i);
				std::cout << "Elem " << i + 1 << ":" << elem.getName() << "," << elem.getStock_refill()<<"," << elem.getPrice()<< "\n";
			}
			break;
		case 3:
			char* name_to_update;
			name_to_update = read_name();
			d = read_date();
			price = read_price();
			Contr_upd_elem(name_to_update, d, price, list);
			break;
		case 4:
			char* name_to_delete;
			name_to_delete = read_name();
			Contr_del_elem(name_to_delete, list);
			break;
		}
		if (cmd != 0)
			cmd = read_command();
	} while (cmd != 0);
}