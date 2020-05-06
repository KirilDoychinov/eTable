#include "DataManager.h" 
#include "Number.h" 
#include "String.h"
#include "DataUtils.h"
#include <iostream>
#include <stack>
#include <cmath>

const Data** DataManager::table = new const Data * [10];


Data* DataManager::createData(std::string str) {
	DataUtils::trim(str);

	Data* d = nullptr;
	if (str.empty())
		d = new String("");

	else if (str.size() > 1 && str.front() == '"' && str.back() == '"')
		d = new String(str);

	else if (DataUtils::isNum(str))
		d = new Number(std::stod(str));

	else if (DataUtils::isFormula(str)) {
		double result = 0;
		if (evaluateFormula(str, result))
			d = new Number(std::stod(str));
		else {
			std::string error = "ERROR";
			d = new String(error);
		}

	}

	return d;
}

double DataManager::evalRef(const std::string& ref) {
	int row = 0, col = 0, i = 0, size = ref.size();
	double val = 0;
	for (i = 0; i < size; ++i)
		if (ref.at(i) == 'C')
			break;

	std::string r = ref.substr(1, i - 1);
	std::string c = ref.substr(i + 1, size - i - 1);
	row = std::stoi(r);
	col = std::stoi(c);

	if (row <= x && col <= y)
		val = table[x][y].evaluate();

	return val;
}

int precedence(const char& ch) {
	int prec = 2;

	if (ch == '*' || ch == '/')
		prec = 3;

	else if (ch == '^')
		prec = 4;

	return prec;
}

bool doNextOperation(std::stack<double>& nums, std::stack<char>& ops) {
	char op = ops.top();
	ops.pop();
	double y = nums.top();
	nums.pop();
	double x = nums.top();
	nums.pop();

	double result = 0;

	if (op == '/' && fabs(y - .0) < 0.001)
		return false;

	result = (op == '+') ? (x + y) : ((op == '-') ? (x - y) : ((op == '*') ? (x * y) : ((op == '/') ? (x / y) : pow(x, y))));
	nums.push(result);

	return true;
}


bool DataManager::evaluateFormula(std::string str, double& d) {
	std::stack<double> nums;
	std::stack<char> ops;

	int i = 0, j = 0, pos = 1;

	for (i = 1; i < str.size(); ++i) {

		char ch = str.at(i);

		if (DataUtils::isMathOperator(ch)) {
			std::string temp = str.substr(pos, str.size() - pos - 1);
			if (temp.front() == 'R')
				nums.push(evalRef(temp));
			else
				nums.push(std::stod(temp));

			pos = i + 1;

			while (!ops.empty() && precedence(ops.top()) >= precedence(ch))
				if (!doNextOperation(nums, ops))
					return false;
			ops.push(ch);
		}

		else if (i == str.size() - 1) {
			std::string temp = str.substr(pos, str.size() - pos);
			if (temp.front() == 'R')
				nums.push(evalRef(temp));
			else
				nums.push(std::stod(temp));

			while (!ops.empty() && precedence(ops.top()) >= precedence(ch))
				if (!doNextOperation(nums, ops))
					return false;
		}
	}

	d = nums.top();
	return true;
}


