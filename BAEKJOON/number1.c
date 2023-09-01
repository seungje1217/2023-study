#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int num[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }

    int v;
    scanf("%d", &v);

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (num[i] == v) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
