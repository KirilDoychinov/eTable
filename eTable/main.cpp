#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include "TableManager.h"

int main()
{

	double d = 1000;


	TableManager::evaluateFormula("=5-7*5 + 2/1", d);
	std::cout << d << std::endl;
}


