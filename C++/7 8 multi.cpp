#include <iostream>

int main() {
	for (int i = 100; i >= 0; i--) {
		if (i % 7 == 0 || i % 8 == 0) {

			std::cout << i << std::endl;

		}
	}
	return 0;
}