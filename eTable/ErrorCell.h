#ifndef ERROR_CELL_H
#define ERROR_CELL_H

#include "Cell.h"

//// private destructor only
class ErrorCell :
	public Cell
{
	friend class Table;
public:
	double evaluate() const;
	std::string toString() const;
	~ErrorCell();

private:
	ErrorCell();
};

#endif



