#include <stdio.h>

int main() {
    int size, i, value, position;

    printf("Input the size of array: ");
    scanf("%d", &size);

    int arr[size + 1];

    printf("Input %d elements in the array:\n", size);
    for(i = 0; i < size; i++) {
        printf("element - %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("The current list of the array: ");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nInput the value to be inserted: ");
    scanf("%d", &value);
    printf("Input the Position, where the value to be inserted: ");
    scanf("%d", &position);


    for(i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    size++;

    printf("After Insert the element the new list: ");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
