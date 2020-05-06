#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

int main()
{
	//double d = 178.999999999999;
	//std::cout << (d == std::floor(d)) << std::endl;
	//std::cout << std::round(d);
	double d = -11.404006;
	//std::cout << (double)d << std::endl;
	//std::cout << (float)d << std::endl;
	int x = std::floor(d), digits = 0;


	while (x != 0) { x /= 10; digits++; }

	std::cout << digits << " " << std::setprecision(digits + 3) << d << std::endl;

	std::cout << std::stod("3.0000") << std::endl;



}


