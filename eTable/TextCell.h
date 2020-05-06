#ifndef TEXT_CELL_H
#define TEXT_CELL_H

#include "Cell.h"

//// private destructor only
class String :
	public Cell
{
	friend class TableManager;
public:
	double evaluate() const;
	void print() const;
	~String();

private:
	String(std::string);
	std::string str;
};

#endif

