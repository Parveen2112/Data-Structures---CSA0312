#include <stdio.h>
void findDuplicates(int arr[], int size) {
    int i, j;
    printf("Duplicate elements are: ");
    for(i = 0; i < size; i++) {
        for(j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                break;
            }
        }
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    findDuplicates(arr, size);
    return 0;
}
