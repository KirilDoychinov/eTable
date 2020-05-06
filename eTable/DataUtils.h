#ifndef DATA_UTILS_H
#define DATA_UTILS_H

#include <string>

namespace DataUtils
{
	bool isDigit(const char&);
	bool isMathOperator(const char& ch);
	void trim(std::string&);
	bool isNum(const std::string&);
	bool isFormula(const std::string&);
};

#endif

