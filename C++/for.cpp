#include <iostream>

int main()
{
	for (int i = 0; i < 10; i++) {

		if (i == 3)
			continue; // i가 3일 때만 건너뒴

		std::cout << i << std::endl;
	}
	return 0;
}