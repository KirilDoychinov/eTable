#include "Table.h" 
#include "NumCell.h" 
#include "TextCell.h"
#include "EmptyCell.h"
#include "ErrorCell.h"
#include "StringUtils.h"
#include <iostream>
#include <iomanip>
#include <stack>
#include <cmath>
#include <cassert>

int getTableIndex(int, int);

/**
 * @brief				  Constructs a table with empty cells from
 * 						  given number of rows and columns
 *
 * @param [in]	rows   	  Number of rows
 *
 * @param [in]	columns	  Number of columns
 */

Table::Table(int rows, int columns) : rows(rows), columns(columns) {
	table = new Cell * [rows * columns];
	for (int i = 0; i < rows * columns; ++i)
		table[i] = new EmptyCell();
}

/**
 * @brief	Destructs the object deallocting dynamic memory
 *
 */

Table::~Table() {
	for (int i = 0; i < rows * columns; ++i)
		delete table[i];
}

/**
 * @brief					Static factory method that creates a cell from given value.
 * 							If the cell is a number, a number cell is created
 * 							If the cell is a string, a text cell is created
 * 							If the cell is either a reference or a formula, it is
 * 							evaluated and the new value is assigned to the cell
 * 							If evaluation fails or the type is unknown, an error cell is produced
 *
 * @param [in,out]	str		Desired cell value
 *
 * @returns					Cell from the evaluated type, or
 * 							ErrorCell if evaluation fails
 */

Cell* Table::createCell(std::string& str) {
	StringUtils::trim(str);

	if (str.empty())
		return new EmptyCell();

	else if (StringUtils::isQuotedText(str))
		return new TextCell(str);

	else if (StringUtils::isNumber(str))
		return new NumCell(std::stod(str));

	else if (StringUtils::isFormula(str)) {
		std::optional<double> result = calculateFormula(str);
		if (result.has_value())
			return new NumCell(result.value());
		std::cout << "Dividing by zero!" << std::endl;;
	}

	return new ErrorCell();
}

/**
 * @brief			Evaluate reference to a floating value,
 * 					0 by default
 *
 * @param 	ref		The reference to be evaluated
 *
 * @returns			Floating result of evaluation, 0 if fails
 */

double Table::evaluateReference(const std::string& ref) const {
	std::string column = "C";
	size_t pos = ref.find_first_of(column);

	if (pos != std::string::npos) {
		std::string row = ref.substr(1, pos - 1);
		std::string col = ref.substr(pos + 1);
		int x = std::stoi(row), y = std::stoi(col);

		if (cellExists(x, y))
			return table[getTableIndex(x, y)]->evaluate();
	}

	return 0.;
}

/**
 * @brief		 Gives precedence value of a mathematical operator as follows:
 * 				 '^' is valued 4, '*' and '/' - 3 and '+' or '-' - 2
 *
 * @param [in]	 ch	Character that is mathematical operator
 *
 * @returns		 Operator precedence value
 *
 * @throws       Assertion error if given character is not an operator
 */

int precedence(const char& ch) {
	return (ch == '*' || ch == '/') ? 3 : (ch == '^') ? 4 : 2;
}

/**
 * @brief					Executes the next operation defined by the last operator
 * 							and the last two recorded operands
 *
 * @param [in,out]	nums	Number stack
 *
 * @param [in,out]	ops 	Operator stack
 *
 * @returns					True if it succeeds, false if it fails.
 */

bool doNextOperation(std::stack<double>& nums, std::stack<char>& ops) {
	char op = ops.top(); ops.pop();
	double y = nums.top(); nums.pop();
	double x = nums.top(); nums.pop();

	if (op == '/' && fabs(y - .0) < 0.001)
		return false;

	double result = (op == '+') ? (x + y) : (op == '-') ? (x - y) : (op == '*') ? (x * y) : (op == '/') ? (x / y) : pow(x, y);
	nums.push(result);

	return true;
}

/**
 * @brief		 Evaluates a given infix-notated formula using Shunting-yard algorithm7
 * 				 in linear O(n) time and space complexity. If evaluation fails, it returns
 * 				 an empty value
 *
 * @param 	str	 The string.
 *
 * @returns		 The floating result of the expression on success, or empty value otherwise
 */

std::optional<double> Table::calculateFormula(const std::string& str) const {
	std::stack<double> nums;
	std::stack<char> ops;

	size_t i = 0, j = 0, pos = 1;

	for (i = 1; i < str.size(); ++i) {

		char ch = str.at(i);

		if (StringUtils::isMathOperator(ch)) {
			std::string temp = str.substr(pos, str.size() - pos - 1);
			if (temp.front() == 'R')
				nums.push(evaluateReference(temp));
			else
				nums.push(std::stod(temp));

			pos = i + 1;

			while (!ops.empty() && precedence(ops.top()) >= precedence(ch))
				if (!doNextOperation(nums, ops)) {
					return std::nullopt;
				}

			ops.push(ch);
		}

		else if (i == str.size() - 1) {
			std::string temp = str.substr(pos, str.size() - pos);
			if (temp.front() == 'R')
				nums.push(evaluateReference(temp));
			else
				nums.push(std::stod(temp));

			while (!ops.empty() && precedence(ops.top()) >= precedence(ch))
				if (!doNextOperation(nums, ops))
					return std::nullopt;
		}
	}

	return nums.top();
}

/**
 * @brief				Check if given cell is in table range
 *
 * @param [in]	row		The cell' row
 *
 * @param [in] 	col		The cell' column
 *
 * @returns				True if cell is valid, false if out of range
 */

bool Table::cellExists(int row, int col) const {
	return row > 0 && col > 0 && row <= rows && col <= columns;
}

/**
 * @brief				Edit the value of given cell
 *
 * @param [in]	row		The cell' row
 *
 * @param [in] 	col		The cell' column
 *
 * @param [in] 	str		New cell value
 *
 * @returns				True on success, false otherwise
 */

bool Table::editCell(int row, int col, std::string& str) {
	if (cellExists(row, col)) {
		delete  table[(row - 1) * 10 + col - 1];
		table[(row - 1) * 10 + col - 1] = nullptr;
		table[(row - 1) * 10 + col - 1] = createCell(str);
		return true;
	}

	return false;
}

/**
 * @brief	Prints the table in format that every column is the same width
 * 			aligned according to the longest cell present there. Cell values
 * 			are enclosed by '|' symbol.
 *
 */

void Table::print() const {

	int* maxSizedColumns = new int[columns];
	for (int i = 0; i < columns; ++i)
		maxSizedColumns[i] = 0;

	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {

			std::string str = table[i * 10 + j]->toString();
			size_t curentCellSize = (StringUtils::isQuotedText(str)) ? str.size() - 2 : str.size();

			if (curentCellSize > maxSizedColumns[j]) {
				maxSizedColumns[j] = curentCellSize;
			}
		}
	}

	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			std::string str = table[i * 10 + j]->toString();
			if (StringUtils::isQuotedText(str))
				str = str.substr(1, str.size() - 2);

			int spaces = maxSizedColumns[j] - str.size();
			std::cout << "| " << std::setw(spaces) << str << " ";
			if (j == columns - 1)
				std::cout << "|" << std::endl;
		}
	}
}

/**
 * @brief	               Stream insertion operator for Table objects
 *
 * @param [in,out]   os	   The output stream
 *
 * @param [in] 	     date  Table to be streamed
 *
 * @returns	               The streamed table object
 *
 */

std::ostream& operator<<(std::ostream& os, const Table& t) {
	char delimeter = ',';

	for (size_t i = 0; i < t.rows; ++i) {
		for (size_t j = 0; j < t.columns; ++j)
			os << t.table[i * 10 + j]->toString() << delimeter;
		os << '\n';
	}

	return os;
}

/**
 * @brief		Gets table acumulated index of cell from
 * 				given row and column
 *
 * @param 	x	cell row
 * @param 	y	cell column
 *
 * @returns		Absolute index of cell
 */

int getTableIndex(int x, int y) {
	return (x - 1) * 10 + y - 1;
}




