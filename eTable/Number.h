#ifndef NUMBER_H
#define NUMBER_H

#include "Data.h"

// private destructor only
class Number :
	public Data
{
	friend class DataFactory;

public:
	double evaluate() const;
	void print() const;
	~Number();
	

private:
	Number(std::string);
	double value;
};

#endif

