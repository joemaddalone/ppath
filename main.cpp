#include <iostream>
#include "PATH.cpp"

int main()
{
	PATH p;
	p.M(0, 0);
	p.L(10, 20);
	p.H(25);
	p.V(25);
	p.Q(10, 10, 10, 10);
	p.t(100, 100);
	p.C(10, 10, 20, 25, 10, 15);
	p.up(100);
	p.close();

	std::cout << p.toString() << std::endl;
};