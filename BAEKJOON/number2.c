#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char a[1000];
    scanf("%s", a);

    int v;
    scanf("%d", &v);

    int sum = 0;
    for (int i = 0; i < strlen(a); i += 2) {
        if (a[i] - '0' == v) {
            sum++;
        }
    }

    printf("%d\n", sum);

    return 0;
}
