#pragma once
#include <ostream>
using namespace std;
class date
{
private:
	int day;
	int month;
	int year;
public:
	date();
	date(int day, int month, int year);
	date(const date& d);
	int getDay();
	int getMonth();
	int getYear();
	void setDay(int newDay);
	void setMonth(int newMonth);
	void setYear(int newYear);
	date& operator = (const date& e);
	bool operator == (const date& e);
	friend ostream& operator<<(ostream& os, const date& s);
	~date();
};

