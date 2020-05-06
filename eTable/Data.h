#ifndef DATA_H
#define DATA_H

#include<iostream>

class Data
{
public:
	virtual double evaluate() const = 0;
	virtual void print() const = 0;
	virtual ~Data();
};

#endif

