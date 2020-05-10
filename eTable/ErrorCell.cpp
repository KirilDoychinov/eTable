#include "ErrorCell.h"
#include "StringUtils.h"

ErrorCell::ErrorCell() {
}

ErrorCell::~ErrorCell() {
}

double ErrorCell::evaluate() const {
	return 0.;
}

void ErrorCell::print() const {
	std::cout << "ERROR";
}


