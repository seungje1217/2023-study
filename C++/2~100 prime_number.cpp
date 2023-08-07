#include <iostream>
int main() {
	for (int i = 2; i <= 100; i++) 
	{
		int b = 0;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				b = 1;
				break;
			}
			else
				continue;
		}
		if (b == 0) 
		{
			std::cout << i << std::endl;
		}
	}
	return 0;
}