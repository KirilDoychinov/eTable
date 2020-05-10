#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <map>
#include "TableManager.h"
#include "TextCell.h"
#include <functional>


void sub() {
	std::cout << "Bad";
}

void test(int* arr) {
	arr[0] = 5;
}

void add();

int main()
{

	double d = 1000;


	//TableManager::evaluateFormula("=5-7*5 + 2/1", d);
	Cell*** table = new Cell * *[100];
	for (int i = 0; i < 100; ++i)
		table[i] = new Cell * [100];

	//table[5][5] = new TextCell("dffdf");
	int arr[] = { 0,8,6,2 };
	test(arr);
	std::cout << *arr << std::endl;

}


