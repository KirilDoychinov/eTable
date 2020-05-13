#include "StringUtils.h"

bool StringUtils::isSign(char ch)
{
	return ch == '+' || ch == '-';
}

bool StringUtils::isDigit(char ch) {
	return ch >= '0' && ch <= '9';
}

bool StringUtils::isMathOperator(char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void StringUtils::trim(std::string& str) {
	if (str.empty())
		return;

	std::string spaceChars = " \t\f\v\n\r";

	std::size_t pos1 = str.find_first_not_of(spaceChars);
	std::size_t pos2 = str.std::string::find_last_not_of(spaceChars);

	if (pos1 != std::string::npos && pos2 != std::string::npos)
		str = str.substr(pos1, pos2 - pos1 + 1);
}

bool StringUtils::isInteger(const std::string& str) {
	bool isInteger = true;

	if (str.empty() || (str.size() == 1 && !isDigit(str.front())))
		isInteger = false;

	else {
		int start = isSign(str.front()) ? 1 : 0;
		std::size_t pos = str.find_first_not_of("0123456789", start);

		if (pos != std::string::npos)
			isInteger = false;
	}

	return isInteger;
}

bool StringUtils::isNumber(const std::string& str) {
	bool isNumber = true;

	if (str.empty() || (str.size() == 1 && !isDigit(str.front())))
		isNumber = false;

	else {
		int start = isSign(str.front()) ? 1 : 0;
		std::string digits = "0123456789";
		std::size_t pos1 = str.find_first_not_of(digits, start);
		std::size_t pos2 = str.std::string::find_last_not_of(digits);

		if (pos1 != std::string::npos && (pos1 != pos2 || str.at(pos1) != '.'))
			isNumber = false;
	}

	return isNumber;
}

bool StringUtils::isReference(const std::string& str) {

	if (str.size() < 4 || str.front() != 'R' || str.at(1) == '0' || str.at(1) == 'C')
		return false;

	bool column = false;

	for (size_t i = 1; i < str.size(); ++i) {
		if (str.at(i) == 'C') {
			if (i == str.size() - 1 || str.at(i + 1) == '0' || column)
				return false;
			column = true;
		}

		else if (!isDigit(str.at(i)))
			return false;
	}

	return column;
}

bool StringUtils::isFormula(const std::string& str) {
	if (str.size() < 2 || str.front() != '=' || isMathOperator(str.back()))
		return false;

	int pos = 1;

	for (size_t i = 1; i < str.size(); ++i) {

		char ch = str.at(i);

		if (isMathOperator(ch) || i == str.size() - 1) {
			int k = ((i == str.size() - 1) ? 1 : 0);
			std::string temp = str.substr(pos, i - pos + k);

			if (isSign(temp.front()) || !(isNumber(temp) || isReference(temp)))
				return false;
			pos = i + 1;
		}
	}

	return true;
}

bool StringUtils::isText(const std::string& str) {
	return str.size() > 1 && str.front() == '"' && str.back() == '"';
}
