#include "StringUtils.h"

bool StringUtils::isSign(const char& ch)
{
	return ch == '+' || ch == '-';
}

bool StringUtils::isDigit(const char& ch) {
	return ch >= '0' && ch <= '9';
}

bool StringUtils::isMathOperator(const char& ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void StringUtils::trim(std::string& str) {
	if (str.empty())
		return;

	std::size_t pos1 = str.find_first_not_of(" \t\f\v\n\r");
	std::size_t pos2 = str.std::string::find_last_not_of(" \t\f\v\n\r");

	if (pos1 != std::string::npos && pos2 != std::string::npos)
		str = str.substr(pos1, pos2 - pos1 + 1);
}

bool StringUtils::isNum(std::string str) {

	if (str.empty() || (str.size() == 1 && !isDigit(str.front())))
		return false;

	int start = isSign(str.front()) ? 1 : 0;

	std::size_t pos1 = str.find_first_not_of("0123456789", start);
	std::size_t pos2 = str.std::string::find_last_not_of("0123456789");

	if (pos1 != std::string::npos && (pos1 != pos2 || str.at(pos1) != '.'))
		return false;

	return true;
}

bool StringUtils::isReference(std::string& str) {

	if (str.size() < 4 || str.front() != 'R' || str.at(1) == '0' || str.at(1) == 'C')
		return false;

	bool hasLetterC = false;

	for (unsigned int i = 1; i < str.size(); ++i) {
		if (str.at(i) == 'C') {
			if (i == str.size() - 1 || str.at(i + 1) == '0' || hasLetterC)
				return false;
			hasLetterC = true;
		}

		else if (!isDigit(str.at(i)))
			return false;
	}

	return hasLetterC;
}

bool StringUtils::isFormula(const std::string& str) {
	if (str.size() < 2 || str.front() != '=' || isMathOperator(str.back()))
		return false;

	int pos = 1;

	for (int i = 1; i < str.size(); ++i) {

		char ch = str.at(i);

		if (isMathOperator(ch) || i == str.size() - 1) {
			int k = ((i == str.size() - 1) ? 1 : 0);
			std::string temp = str.substr(pos, i - pos + k);

			if (isSign(temp.front()) || !(isNum(temp) || isReference(temp)))
				return false;
			pos = i + 1;
		}
	}

	return true;
}
