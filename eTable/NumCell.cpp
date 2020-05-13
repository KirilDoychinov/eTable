#include "NumCell.h"
#include <iomanip>
#include <string>
#include <sstream>

NumCell::NumCell(double d) : value(d) {
}

NumCell::~NumCell() {
}

double NumCell::evaluate() const {
	return value;
}

std::string NumCell::toString() const {
	if (std::fabs(value - std::round(value)) < 0.001)
		return std::to_string((int)std::round(value));

	int x = std::round(1000 * value), precision = 1;

	if (x % 100 != 0) {
		++precision;
		if (x % 10 != 0)
			++precision;
	}

	std::stringstream ss;
	ss << std::fixed << std::setprecision(precision) << value;
	return ss.str();
}




