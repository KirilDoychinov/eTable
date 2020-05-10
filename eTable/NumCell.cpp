#include "NumCell.h"
#include <iomanip>
#include <string>

int digits(double);

NumCell::NumCell(double d) : value(d) {
}

NumCell::~NumCell() {
}

double NumCell::evaluate() const {
	return value;
}

void NumCell::print() const {
	if (std::fabs(value - std::round(value)) < 0.001)
		std::cout << std::round(value);
	else
		std::cout << std::setprecision((double)digits(value) + 3) << value;
}

int digits(double d) {
	int x = std::floor(d), digits = 0;

	while (x != 0) {
		x /= 10;
		++digits;
	}

	return digits;
}


