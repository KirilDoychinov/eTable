#include "EmptyCell.h"

EmptyCell::EmptyCell() {
}

EmptyCell::~EmptyCell() {
}

double EmptyCell::evaluate() const {
	return 0.;
}

std::string EmptyCell::toString() const {
	return "";
}