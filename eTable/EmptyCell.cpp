#include "EmptyCell.h"

EmptyCell::EmptyCell() {
}

EmptyCell::~EmptyCell() {
}

double EmptyCell::evaluate() const {
	return 0.;
}

void EmptyCell::print() const {
	std::cout << "";
}