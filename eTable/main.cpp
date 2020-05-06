#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include "DataManager.h"

int main()
{

	double d = 1000;


	DataManager::evaluateFormula("=5-7*5 + 2/1", d);
	std::cout << d << std::endl;
}


