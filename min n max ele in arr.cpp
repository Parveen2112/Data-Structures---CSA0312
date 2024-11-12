#include <stdio.h>
int main() {
    int arr[] = {4, 7, 2, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
    return 0;
}

