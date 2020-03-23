#include "date.h"
#include <ostream>
#include <iostream>
using namespace std;
date::date() {
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

date::date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

date::date(const date& e) {
	this->day = e.day;
	this->month = e.month;
	this->year = e.year;
}

int date::getDay() {
	return this->day;
}

int date::getMonth() {
	return this->month;
}

int date::getYear() {
	return this->year;
}

void date::setDay(int newDay) {
	this->day = newDay;
}

void date::setMonth(int newMonth) {
	this->month = newMonth;
}

void date::setYear(int newYear) {
	this->year = newYear;
}

date& date::operator=(const date& d) {
	this->setDay(d.day);
	this->setMonth(d.month);
	this->setYear(d.year);
	return *this;
}
bool date:: operator==(const date& s) {
	if (this->day == s.day)
		if (this->month == s.month)
			if (this->year == s.year)
				return true;
			else
				return false;
		else
			return false;
	else 
		return false;
}

ostream& operator<<(ostream& os, const date& d) {
	os << d.day << "." << d.month << "." << d.year;
	return os;
}

date::~date() {
	if (this->day) {
		this->day = 0;
	}
	if (this->month) {
		this->month = 0;
	}
	if (this->year) {
		this->year = 0;
	}
}