#include "TextCell.h"
#include "StringUtils.h"
#include <string>

TextCell::TextCell(const std::string& str) :str(str) {
}

TextCell::~TextCell() {
}

double TextCell::evaluate() const {
	double value = 0.;
	std::string noQuotes = str.substr(1, str.size() - 2);

	if (StringUtils::isNumber(noQuotes))
		value = std::stod(str);

	return value;
}

void TextCell::print() const {
	std::cout << str;
}

