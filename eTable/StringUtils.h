#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>

namespace StringUtils
{
	bool isDigit(const char&);
	bool isMathOperator(const char& ch);
	void trim(std::string&);
	bool isNum(const std::string&);
	bool isFormula(const std::string&);
	bool isRef(std::string&);
};

#endif

