// 사분면 고르기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x,y;

    scanf("%d",&x);
    scanf("%d",&y);

    if (x>1 && y>1)
    {
        printf("1");
    }
    if (x<1 && y>1)
    {
        printf("2");
    }
    if (x<1 && y<1)
    {
        printf("3");
    }
    if (x>1 && y<1)
    {
        printf("4");
    }
    return 0;
}
