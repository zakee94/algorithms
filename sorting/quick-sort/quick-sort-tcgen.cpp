#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;
#define SIZE 100000000

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    int i;

    ofstream outFile;
    outFile.open("input.txt");

    for (i = 0; i < size; i++)
        outFile << arr[i] << "\n";

    outFile.close();
}

void initArray(int arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

void shuffle(int arr[], int size) {
    int rand_index, j = size - 1, i;

    for (i = 0; i < j; i++) {
        rand_index = rand() % j;
        swap(&arr[rand_index], &arr[j]);
        j--;
    }
}

int main() {
    int* arr = (int*)malloc(sizeof(int)*SIZE);

    srand(time(NULL));
    initArray(arr, SIZE);
    shuffle(arr, SIZE);
    printArray(arr, SIZE);

    free(arr);
    return 0;
}
