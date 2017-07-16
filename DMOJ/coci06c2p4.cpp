#include <iostream>

int main() {
    int a, n;
    scanf("%d", &n);
    a = (n * (n-1) * (n-2) * (n-3)) / 24;
    printf("%d", a);
}