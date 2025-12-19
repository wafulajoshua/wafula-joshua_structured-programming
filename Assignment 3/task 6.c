#include <stdio.h>


void incrementByValue(int num) {
    num = num + 1;
}


void incrementByReference(int *num) {
    *num = *num + 1;
}

int main() {
    int value = 10;

    printf("Original value: %d\n", value);


    incrementByValue(value);
    printf("After incrementByValue: %d\n", value);


    incrementByReference(&value);
    printf("After incrementByReference: %d\n", value);

    return 0;
}
