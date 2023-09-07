#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char a[1000];
    for (int i = 0; i < n; ++i) {
        scanf("%s", a + i * 2);
    }

    int v;
    scanf("%d", &v);

    int count = 0;
    for (int i = 0; i < n; i += 2) {
        if (atoi(a + i) == v) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
