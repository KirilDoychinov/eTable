#ifndef CELL_H
#define CELL_H

#include <string>

/**
 * @class	Cell
 *
 * @brief	 Pure abstract class representing a table cell. Class cannot
 * 			 be instantinated and possess only virtual methods that 
 * 			 must be overriden in all derived classes
 *
 */

class Cell
{
public:
	virtual double evaluate() const = 0;
	virtual std::string toString() const = 0;
	virtual ~Cell();
};

#endif

