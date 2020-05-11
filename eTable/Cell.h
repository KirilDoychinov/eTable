#ifndef CELL_H
#define CELL_H

#include<iostream>

class Cell
{
public:
	virtual double evaluate() const = 0;
	virtual std::string toString() const = 0;
	virtual ~Cell();
};

#endif

