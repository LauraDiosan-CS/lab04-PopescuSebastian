#pragma once
#include "date.h";
int read_command();
char* read_name();
int read_day();
int read_month_cmd();
int read_month(int&);
int read_year_cmd();
int read_year(int&, int&);
date read_date();
float read_price();