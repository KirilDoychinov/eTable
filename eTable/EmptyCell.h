#ifndef EMPTY_CELL_H
#define EMPTY_CELL_H

#include "Cell.h"

//// private destructor only
class EmptyCell :
	public Cell
{
	friend class Table;
public:
	double evaluate() const;
	std::string toString() const;
	~EmptyCell();

private:
	EmptyCell();
};

#endif

