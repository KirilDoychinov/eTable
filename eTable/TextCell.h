#ifndef TEXT_CELL_H
#define TEXT_CELL_H

#include "Cell.h"

//// private destructor only
class TextCell :
	public Cell
{
	friend class Table;
public:
	double evaluate() const;
	std::string toString() const;
	~TextCell();

private:
	TextCell(const std::string&);
	std::string str;
};

#endif

