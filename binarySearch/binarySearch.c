#include <stdio.h>

int binarySearch(int a[], int left, int right, int n);
int binarySearch(int a[], int left, int right, int n) {
    if (left > right) {
        return -1;
    }

    int medium = (left + right) / 2;
    if (a[medium] == n) {
        return medium;
    }

    if (a[medium] < n) {
        return binarySearch(a, medium++, right, n);
    }
    return binarySearch(a, left, medium++, n);
}

int main() {
    int a[] = {1, 5, 7, 10, 12, 16, 24};
    int length = sizeof(a)/sizeof(a[0]);
    int number = 24;
    int index = binarySearch(a, 0, length, number);

    printf("Index found is: %d\n", index);

    return 0;
}