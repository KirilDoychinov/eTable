#ifndef TABLE_MANAGER_F
#define TABLE_MANAGER_F

#include "Cell.h"
#include <optional>
#include <vector>

class TableManager
{
public:
	TableManager(int, int);
	~TableManager();

	Cell* createCell(std::string&);
	Cell* getCell(int, int);
	double evaluateRef(const std::string&);
	std::optional<double> evaluateFormula(const std::string&);
	void editCell(int, int, std::string&);
	bool cellExists(int, int);

private:
	int rows;
	int columns;
	std::vector<std::vector<Cell*>> table;
};

#endif

