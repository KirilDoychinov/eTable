#ifndef STRING_H
#define STRING_H

#include "Data.h"

//// private destructor only
class String :
	public Data
{
	friend class DataManager;
public:
	double evaluate() const;
	void print() const;
	~String();

private:
	String(std::string);
	std::string str;
};

#endif

