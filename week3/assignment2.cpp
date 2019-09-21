#include <iostream>

int main() {
	char* a = "ABC";
	char b[] = "ABC";
	
	std::cout << a << std::endl;
	
	b[0] = 'b';
	std::cout << b << std::endl;

	a[0] = 'b';
	std::cout << a << std::endl;
	std::cout << b << std::endl;
}
