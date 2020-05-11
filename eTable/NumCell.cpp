#include "NumCell.h"
#include <iomanip>
#include <string>
#include <sstream>

int digits(double);

NumCell::NumCell(double d) : value(d) {
}

NumCell::~NumCell() {
}

double NumCell::evaluate() const {
	return value;
}

std::string NumCell::toString() const {
	std::stringstream ss;

	if (std::fabs(value - std::round(value)) < 0.001)
		ss << std::round(value);
	else
		ss << std::setprecision((double)digits(value) + 3) << value;

	return ss.str();
}

int digits(double d) {
	int x = std::floor(d), digits = 0;

	while (x != 0) {
		x /= 10;
		++digits;
	}

	return digits;
}


