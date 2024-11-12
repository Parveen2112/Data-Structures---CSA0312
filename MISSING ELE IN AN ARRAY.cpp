#include <stdio.h>
void findMissingElements(int arr[], int n) {
    int total = (n + 1) * (n + 2) / 2; 
    int sum = 0;  
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }   
    int missing = total - sum;
    printf("The missing element is: %d\n", missing);
}
int main() {
    int arr[] = {1, 2, 4, 5, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    findMissingElements(arr, n);
    return 0;
}
