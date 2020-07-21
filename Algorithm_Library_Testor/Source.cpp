#include <iostream>

#include "AALg.cpp"

int main() {
	int a[10];

	for (int i = 0; i < 10; ++i) {
		a[i] = i;
		std::cout << a[i];
	}
	std::cout << std::endl;

	MergeSort(a, 10);

	for (int i = 0; i < 10; ++i)
		std::cout << a[i];

	std::cout << std::endl;

	return EXIT_SUCCESS;
}