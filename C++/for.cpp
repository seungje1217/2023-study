#include <iostream>

int main()
{
	for (int i = 0; i < 100; i++) 
	{
		if (i == 3)
			continue; // i가 3일 때만 건너뜀
		if (i==4)
			continue; // i가 4일 때만 건너뜀

		std::cout << i << std::endl;
	}
	return 0;
}