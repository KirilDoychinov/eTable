#include "ErrorCell.h"
#include "StringUtils.h"

ErrorCell::ErrorCell() {
}

ErrorCell::~ErrorCell() {
}

double ErrorCell::evaluate() const {
	return 0.;
}

std::string ErrorCell::toString() const {
	return "ERROR";
}


