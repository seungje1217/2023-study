// n을 입력받아서 1부터 n까지의 합을 구하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int sum = 0;
	int n=0;

	printf("정수 입력 : ");
	scanf("%d", &n);

	for (int i=1;i<=n;i++) 
	{
		sum += i;
		
	}

	printf("%d",sum);
	
}


