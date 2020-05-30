#ifndef TABLE_H
#define TABLE_H

#include "Cell.h"
#include <optional>
#include <vector>

/**
 * @class	Table
 *
 * @brief	Class representing a table entity
 * 			containing cells from diferent types
 *
 */

class Table
{
public:
	Table(int, int);
	~Table();

	Cell* createCell(std::string&);
	bool editCell(int, int, std::string&);
	void print() const;
	friend std::ostream& operator<<(std::ostream&, const Table&);
	std::optional<double> calculateFormula(const std::string&) const;

private:
	/**
	* @brief Number of table rows
	*/

	int rows;

	/**
	* @brief Number of table columns
	*/

	int columns;

	/**
	* @brief Table cells
	*/

	Cell** table;

	bool cellExists(int, int) const;
	double evaluateReference(const std::string&) const;
	
};

#endif

