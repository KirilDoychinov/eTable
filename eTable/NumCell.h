#ifndef NUM_CELL_H
#define NUM_CELL_H

#include "Cell.h"

// private destructor only
class NumCell :
	public Cell
{
	friend class Table;

public:
	double evaluate() const;
	std::string toString() const;
	~NumCell();
	
private:
	NumCell(double);
	double value;
};

#endif

