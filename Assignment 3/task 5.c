#include <stdio.h>


void swapNumbers(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 5, b = 10;

    printf("Before swapping:\n");
    printf("a = %d, b = %d\n", a, b);
    swapNumbers(&a, &b);

    printf("After swapping:\n");
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
