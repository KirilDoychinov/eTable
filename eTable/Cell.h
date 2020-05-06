#ifndef CELL_H
#define CELL_H

#include<iostream>

class Cell
{
public:
	virtual double evaluate() const = 0;
	virtual void print() const = 0;
	virtual ~Cell();
};

#endif

