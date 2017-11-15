// Very useful for generating test cases and to generate random numbers
// with no duplicates.

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
#define SIZE 100

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void initArray(int arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

// Select a random elment from array(n) and swap it with the last elment.
// Again select a random elment from array(n-1, except last element) and ...
// Repeat.
void shuffle(int arr[], int size) {
    int rand_index, j = size - 1, i;

    for (i = 0; i < j; i++) {
        rand_index = rand() % j;
        swap(&arr[rand_index], &arr[j]);
        j--;
    }
}

int main() {
    int arr[SIZE];

    srand(time(NULL));
    initArray(arr, SIZE);
    shuffle(arr, SIZE);
    printArray(arr, SIZE);

    return 0;
}
