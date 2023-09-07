// 알람 시계
#include <stdio.h>

int main(void) {
    int a, b;

    printf("시: ");
    scanf("%d", &a);

    printf("분: ");
    scanf("%d", &b);

    if (b >= 45)
    {
        b -= 45;
    } 
    else
     {
        b = b + 60 - 45;
        if (a == 0) 
        {
            a = 23;
        } 
        else 
        {
            a -= 1;
        }
    }

    printf("%d %d\n", a, b);

    return 0;
}
