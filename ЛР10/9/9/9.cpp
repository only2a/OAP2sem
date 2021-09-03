#include <stdio.h>

int add(int n, int m) {
    return (0 < m) ? add(n + 1, m - 1) : n;
}

int sub(int n, int m) {
    return (0 < m) ? sub(n - 1, m - 1) : n;
}

int mul(int n, int m) {
    return (0 < m) ? add(n, mul(n, m - 1)) : 0;
}

int pow(int n, int m) {
    return (0 < m) ? mul(n, pow(n, m - 1)) : 1;
}

int main() {
    int m, n;

    if ((scanf_s("%d %d", &n, &m) == 2) && (0 <= n) && (0 <= m)) {
        printf("Cумма = %d\n", add(n, m));
        printf("разность = %d\n", sub(n, m));
        printf("умножение = %d\n", mul(n, m));
        printf("возведение в степень = %d\n", pow(n, m));
    }

    return 0;
}