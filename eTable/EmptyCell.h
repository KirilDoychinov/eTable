#ifndef EMPTY_CELL_H
#define EMPTY_CELL_H

#include "Cell.h"

//// private destructor only
class EmptyCell :
	public Cell
{
	friend class TableManager;
public:
	double evaluate() const;
	void print() const;
	~EmptyCell();

private:
	EmptyCell();
};

#endif

