#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>

namespace StringUtils
{
	bool isDigit(const char&);
	bool isMathOperator(const char&);
	void trim(std::string&);
	bool isNum(std::string);
	bool isSign(const char&);
	bool isFormula(const std::string&);
	bool isReference(std::string&);
};

#endif

