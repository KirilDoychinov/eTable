#ifndef DATA_MANAGER_F
#define DATA_MANAGER_F

#include "Data.h"

class DataManager
{
public:
	static Data* createData(std::string);
	static double evalRef(const std::string&);
	static bool evaluateFormula(std::string, double&);


	const static int x = 100, y = 200;
	const static Data** table;

};

#endif

