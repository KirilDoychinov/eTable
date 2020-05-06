#include "DataUtils.h"

bool DataUtils::isDigit(const char& ch) {
	return ch >= '0' && ch <= '9';
}

bool DataUtils::isMathOperator(const char& ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void DataUtils::trim(std::string& str) {
	int pos = -1, i, j;

	for (i = 0; i < str.size(); ++i) {
		if (str.at(i) != ' ') {
			pos = i;
			break;
		}
	}

	if (pos == -1) {
		str = "";
		return;
	}

	for (j = str.size() - 1; j > 0; --j)
		if (str.at(j) != ' ')
			break;

	str = str.substr(pos, j - i + 1);
}

bool DataUtils::isNum(const std::string& str) {
	bool hasFloatingPoint = false, result = true;
	char ch = str.front();

	if (ch != '+' && ch != '-' && !isDigit(ch))
		result = false;

	if (ch == '0' && str.size() > 1 && str.at(1) != '.')
		result = false;

	if (result) {
		for (unsigned int i = 1; i < str.size(); ++i) {
			ch = str.at(i);

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
	}

	//single return policy
	return result;
}

bool isFormula(const std::string& str) {



}
