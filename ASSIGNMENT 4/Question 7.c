#include <stdio.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int start = 0;
int count = 0;

void insertSample(int value) {
    int index = (start + count) % BUFFER_SIZE;
    if (count < BUFFER_SIZE) {
        buffer[index] = value;
        count++;
    } else {
        buffer[start] = value;
        start = (start + 1) % BUFFER_SIZE;
    }
}

void printSamples() {
    printf("Stored samples (oldest → newest): ");
    for (int i = 0; i < count; i++) {
        int index = (start + i) % BUFFER_SIZE;
        printf("%d ", buffer[index]);
    }
    printf("\n");
}

int main() {
    int value;
    char choice;

    printf("Circular Data Logger (Buffer size: %d)\n", BUFFER_SIZE);

    do {
        printf("Enter sensor value to log: ");
        scanf("%d", &value);
        insertSample(value);

        printSamples();

        printf("Do you want to enter another value? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

