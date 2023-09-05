#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int a, b, sum;
        
        printf("정수1 입력: ");
        scanf("%d", &a);

        printf("정수2 입력: ");
        scanf("%d", &b);

        sum = a + b;

        printf("case #%d: %d + %d = %d\n", i + 1, a, b, sum);
    }
    
    return 0;
}