#pragma once

#include "stdafx.h"

struct Date {
	int day;
	int mounth;
	int year;
	Date(int _day, int _mounth, int _year) {
		day = _day;
		mounth = _mounth;
		year = _year;
	}
};

vector<string> Split(string in_str, const char* delimiter);
Date DateFromString(string in_str);
string DateToString(Date in_date);
string input(istream& strm);

