#ifndef TABLE_MANAGER_F
#define TABLE_MANAGER_F

#include "Cell.h"

class TableManager
{
public:
	static Cell* createData(std::string);
	static double evalRef(const std::string&);
	static bool evaluateFormula(std::string, double&);


	const static int x = 100, y = 200;
	const static Cell** table;

};

#endif

