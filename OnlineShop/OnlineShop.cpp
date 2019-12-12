#ifndef SYSTEM_H
	#include "System.h"
#endif // !SYSTEM_H

int main()
{
	setlocale(LC_ALL, "ru");	

	System sys;
	sys.Start();

	return 0;
}