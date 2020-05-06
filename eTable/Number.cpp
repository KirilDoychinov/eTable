#include "Number.h"
#include <iomanip>
#include <string>

int digits(double);

Number::Number(double d) : value(d) {
}

Number::~Number() {
}

double Number::evaluate() const {
	return value;
}

void Number::print() const {
	if (std::fabs(value - std::round(value)) < 0.001)
		std::cout << std::round(value);
	else
		std::cout << std::setprecision(digits(value) + 3) << value;
}

int digits(double d) {
	int x = std::floor(d), digits = 0;

	while (x != 0) {
		x /= 10; ++digits;
	}

	return digits;
}


