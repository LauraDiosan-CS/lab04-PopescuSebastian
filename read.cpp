#include "read.h"
#include <iostream>
using namespace std;

int read_command() {
	int cmd;
	std::cout << "Command:"; std::cin >> cmd;
	if (!cin) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please input a number between 0 and 9!\n";
		return read_command();
	}
	if (cmd < 0 || cmd > 9) {
		std::cout << "Please input a number between 0 and 9!\n";
		return read_command();
	}
	return cmd;
}


char* read_name() {
	char* name = new char[20];
	std::cout << "Name:"; std::cin >> name;
	return name;
}

int read_day() {
	int day;
	std::cout << "Day: "; std::cin >> day;
	if (!cin) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please input a number between 1 and 31!\n";
		return read_day();
	}
	while (day < 1 || day > 31) {
		std::cout << "Incorrect day! Try again!\n";
		std::cout << "Day: "; std::cin >> day;
		if (!cin) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please input a number between 1 and 31!\n";
			return read_day();
		}
	}
	return day;
}

int read_month_cmd() {
	int cmd;
	std::cout << "Press 1 to re enter day or 2 to re enter month: ";
	std::cin >> cmd;
	if (!cin) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please input a number between 1 and 2!\n";
		read_month_cmd();
	}
	return cmd;
}

int read_month(int& day) {
	int month;
	std::cout << "Month: "; std::cin >> month;
	if (!cin) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please input a number between 1 and 12!\n";
		return read_month(day);
	}
	while (month < 1 || month >12) {
		std::cout << "Incorrect month! Try again!\n";
		std::cout << "Month: "; std::cin >> month;
		if (!cin) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please input a number between 1 and 12!\n";
		}
	}
	if (month == 2 && day > 29) {
		int cmd;
		std::cout << "February can't have so many days!\n";
		cmd = read_month_cmd();
		while (cmd != 1 && cmd != 2) {
			std::cout << "Wrong command! Try again:";
			cmd = read_month_cmd();
		}
		if (cmd == 1)
			day = read_day();
		if (cmd == 2)
			month = read_month(day);
	}
	return month;
}

int read_year_cmd() {
	int cmd;
	std::cout << "Press 1 to re enter day, 2 to re enter month or 3 to re enter year: ";
	std::cin >> cmd;
	if (!cin) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please input a number between 1, 2 and 3!\n";
		read_year_cmd();
	}
	return cmd;
}

int read_year(int& day, int& month) {
	int year;
	std::cout << "Year: "; std::cin >> year;
	if (!cin) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please input a number between 1600 and 2020!\n";
		return read_year(day, month);
	}
	while (year < 1600 || year > 2020) {
		std::cout << "Incorrect year! Try again!\n";
		std::cout << "Year: "; std::cin >> year;
		if (!cin) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please input a number between 1600 and 2020!\n";
		}
	}
	if (year % 4 != 0)
		if (month == 2 && day == 29) {
			int cmd;
			std::cout << "The year " << year << " is not a leap year! February can't have 29 days!\n";
			cmd = read_year_cmd();
			while (cmd != 1 && cmd != 2 && cmd != 3) {
				std::cout << "Wrong command! Try again: ";
				cmd = read_year_cmd();
			}
			if (cmd == 1)
				day = read_day();
			if (cmd == 2)
				month = read_month(day);
			if (cmd == 3)
				year = read_year(day, month);
		}
	return year;
}

date read_date() {
	date d;
	int day, month, year;
	day = read_day();
	month = read_month(day);
	year = read_year(day, month);
	d.setDay(day);
	d.setMonth(month);
	d.setYear(year);
	return d;
}

int read_price_cmd() {
	int cmd;
	std::cout << "You are giving this product for free, are you sure? Press 1 to confirm or to 2 to re enter the price: "; 
	std::cin >> cmd;
	if (!cin) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please input a number between 1 and 2!\n";
		return read_price_cmd();
	}
	return cmd;
}

float read_price() {
	float p;
	std::cout << "Price:"; std::cin >> p;
	if (!cin) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please input a number grater than 0!\n";
		return read_price();
	}
	while (p < 0) {
		std::cout << "A product can't have a negative price! Please re enter the price: ";
		std::cin >> p;
		if (!cin) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please input a number grater than 0!\n";
			return read_price();
		}
	}
	if (p == 0) {
		int cmd;
		cmd = read_price_cmd();
		while (cmd != 1 && cmd != 2) {
			std::cout << "Wrong command! Try again:";
			cmd = read_price_cmd();
		}
		if (cmd == 1)
			std::cout << "Good job! You are helping other people!\n";
		if (cmd == 2)
			return read_price();
	}
	return p;
}