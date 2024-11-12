#include <stdio.h>
int isPrime(int num, int divisor) {
    if (num < 2) return 0;
    if (divisor == 1) return 1;
    if (num % divisor == 0) return 0;
    return isPrime(num, divisor - 1);
}
void printPrimes(int n) {
    for (int i = 2; i <= n; i++) {
        if (isPrime(i, i / 2)) {
            printf("%d ", i);
        }
    }
}
int main() {
    int n;
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Prime numbers up to %d are: ", n);
    printPrimes(n);
    return 0;
}
