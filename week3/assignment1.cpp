#include <iostream>

using namespace std;

void code() {}

int main() {
	
	char * rodata = "rodata";
	static int data = 10;
	static int bss;
	int* heap = new int[2];
	int stack = 5;
	
	cout << "code\t" << (void*) code << endl;
	cout << "Rodata\t" << (void*) rodata << endl;
	cout << "data\t" << &data << endl;
	cout << "BSS\t" << &bss << endl;
	cout << "HEAP\t" << heap << endl;
	cout << "Stack\t" << &stack << endl;
}
