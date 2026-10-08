#include <stdio.h>
#include <stdlib.h> // for abs() and qsort()

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    qsort(arr1, arr1Size, sizeof(int), compare);
    qsort(arr2, arr2Size, sizeof(int), compare);
    int i = 0, j = 0, count = 0;

    while (i < arr1Size) {
        while (j < arr2Size && arr2[j] < arr1[i] - d) j++;
        if (j < arr2Size && abs(arr1[i] - arr2[j]) <= d) {
            i++;
        } else {
            count++;
            i++;
        }
    }

    return count;
}
