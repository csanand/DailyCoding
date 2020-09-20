/*
Author : Anand
Problem statement : Implement division of two positive integers
                    without using the division, multiplication
                    or modulus operators.
                    Return the quotient as an integer,
                    ignoring the remainder.
Compilation Link: cpp.sh/2zjtb

*/
#include <iostream>

int& division(int num, int divisor,  int& quotient);

int main()
{
	int divisor, divident, quotient;
	std::cout << "Enter Divident\n";
	std::cin >> divident;
	std::cout << "Enter Divisor\n";
	std::cin >> divisor;

	division(divident, divisor, quotient);

	std::cout << "Quotient is : "<< quotient;
	return 0;
}

int& division(int num, int divisor, int& quotient)
{
	quotient = 0;
	while (num > divisor)
	{
		num -= divisor;
		quotient++;
	}
	return quotient;
}
