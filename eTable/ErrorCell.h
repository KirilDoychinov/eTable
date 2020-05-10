#ifndef ERROR_CELL_H
#define ERROR_CELL_H

#include "Cell.h"

//// private destructor only
class ErrorCell :
	public Cell
{
	friend class TableManager;
public:
	double evaluate() const;
	void print() const;
	~ErrorCell();

private:
	ErrorCell();
};

#endif



