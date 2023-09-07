// A+B-8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int* a = (int*)malloc(n * sizeof(int)); // 동적 배열 선언
    int* b = (int*)malloc(n * sizeof(int));
    int* sum = (int*)malloc(n * sizeof(int));

    if (a == NULL || b == NULL || sum == NULL) {
        printf("메모리 할당 실패\n");
        return 1; // 실패 상태 코드 반환
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i], &b[i]);

        sum[i] = a[i] + b[i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("Case #%d: %d + %d = %d\n", i + 1, a[i], b[i], sum[i]);
    }

    // 동적으로 할당한 메모리 해제
    free(a);
    free(b);
    free(sum);

    return 0;
}
