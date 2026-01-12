#include <stdio.h>

int main() {
    int rows = 6, cols = 4;
    int arr[6][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    };

    // Traverse and print each element
    printf("2D Array Elements:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Element at [%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }

    return 0;
}
