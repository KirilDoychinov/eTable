#ifndef TABLE_H
#define TABLE_H

#include "Cell.h"
#include <optional>
#include <vector>

class Table
{
public:
	Table(int, int);
	~Table();

	Cell* createCell(std::string&);
	void editCell(int, int, std::string&);
	void print() const;
	friend std::ostream& operator<<(std::ostream&, const Table&);

private:
	int rows;
	int columns;
	std::vector<std::vector<Cell*>> table;

	bool cellExists(int, int) const;
	double evaluateReference(const std::string&) const;
	std::optional<double> calculateFormula(const std::string&) const;
};

#endif

