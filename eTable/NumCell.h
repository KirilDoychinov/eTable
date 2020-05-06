#ifndef NUM_CELL_H
#define NUM_CELL_H

#include "Cell.h"

// private destructor only
class NumCell :
	public Cell
{
	friend class TableManager;

public:
	double evaluate() const;
	void print() const;
	~NumCell();
	
private:
	NumCell(double);
	double value;
};

#endif

