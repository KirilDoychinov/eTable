#include "StringUtils.h"

bool StringUtils::isDigit(const char& ch) {
	return ch >= '0' && ch <= '9';
}

bool StringUtils::isMathOperator(const char& ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void StringUtils::trim(std::string& str) {
	if (str.empty())
		return;

	std::size_t pos1, pos2;
	pos1 = str.find_first_not_of(" \t\f\v\n\r");
	pos2 = str.std::string::find_last_not_of(" \t\f\v\n\r");

	if (pos1 != std::string::npos && pos2 != std::string::npos)
		str = str.substr(pos1, pos2 - pos1 + 1);
}

bool StringUtils::isNum(const std::string& str) {
	bool hasFloatingPoint = false, result = true;

	if (str.empty() || (str.front() != '+' && str.front() != '-' && (!isDigit(str.front()))))
		result = false;

	else
		for (unsigned int i = 1; i < str.size(); ++i) {
			char ch = str.at(i);

			if (ch == '.') {
				if (hasFloatingPoint) {
					result = false;
					break;
				}

				hasFloatingPoint = true;
			}

			else if (!isDigit(ch)) {
				result = false;
				break;
			}
		}

	return result;
}

bool StringUtils::isReference(std::string& str) {
	if (str.size() < 4 || str.front() != 'R' || str.at(1) == '0' || str.at(1) == 'C')
		return false;

	int posColumn = -1, i = 1;
	for (i = 1; i < str.size(); ++i) {
		char ch = str.at(i);

		if (ch == 'C') {
			if (i == str.size() - 1 || str.at(i + 1) == '0')
				return false;
			break;
		}

		else if (!isDigit(ch))
			return false;
	}

	for (int j = i + 1; j < str.size(); ++j)
		if (!isDigit(str.at(j)))
			return false;

	return true;
}

bool StringUtils::isFormula(const std::string& str) {
	if (str.size() < 2 || str.front() != '=')
		return false;

	int pos = 1;
	bool result = true;
	for (int i = 1; i < str.size(); ++i) {

		char ch = str.at(i);

		if (i == str.size() - 1) {
			if (isMathOperator(ch)) {
				result = false;
				break;
			}


			std::string temp = str.substr(pos, i - pos + 1);
			if (!(isNum(temp) || isReference(temp))) {
				result = false;
				break;
			}
		}

		else if (isMathOperator(ch)) {

			std::string temp = str.substr(pos, i - pos);

			if (!(isNum(temp) && isReference(temp))) {
				result = false;
				break;
			}
			pos = i + 1;
		}

	}

	return result;
}
