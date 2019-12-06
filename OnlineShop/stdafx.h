#pragma once

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <string.h>
#include <memory>
#include <sstream>
#include <fstream>
#include <Windows.h>

using namespace std;

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