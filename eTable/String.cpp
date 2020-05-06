#include "String.h"
#include "DataUtils.h"
#include <string>

String::String(std::string str) :str(str) {
}

String::~String() {
}

double String::evaluate() const {
	double value = 0;
	std::string noQuotes = str.substr(1, str.size() - 2);

	if (DataUtils::isNum(noQuotes))
		value = std::stod(str);

	return value;
}

void String::print() const {
	std::cout << str;
}

