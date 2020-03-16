#include "run.h"
#include "entity.h"
#include "repo.h"
#include "Controller.h"
#include <iostream>
void menu() {
	std::cout <<"Menu:\n";
	std::cout << "0 : EXIT\n";
	std::cout << "1 : Add\n";
	std::cout << "2 : Print\n";
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

void run_program() {
	int cmd;
	cmd = read_command();
	Repo list[15];
	do {
		switch (cmd) {
		case 1:
			char* name;
			name = read_name();
			list->addEntity(Contr_add_elem(name));
			break;
		case 2:
			int size_list = list->getSize();
			for (int i = 0; i < size_list; i++) {
				Product elem = list->getElem(i);
				std::cout << "Elem " << i + 1 << ":" << elem.getName() << "\n";
			}
			break;
		}
		if (cmd != 0)
			cmd = read_command();
	} while (cmd != 0);
}