#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <map>
#include "TableManager.h"
#include <functional>


void sub() {
	std::cout << "Bad";
}

void add();

int main()
{

	double d = 1000;


	TableManager::evaluateFormula("=5-7*5 + 2/1", d);



}


