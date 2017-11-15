#include <stdlib.h>
#include <iostream>
#include <utility>

using namespace std;

#define PARENT(i) i/2
#define R_CHILD(i) (2*i)+1
#define L_CHILD(i) 2*i

int size = 0, *arr;

void bubbleUp() {
    int temp, i = size;

    while((arr[i] > arr[PARENT(i)]) && (i > 1)) {
        swap(arr[i], arr[PARENT(i)]);
        i = PARENT(i);
    }
}

void sinkDown() {
    int i = 1;
    bool loop = true;

    while(loop) {
        if (size >= R_CHILD(i) || size >= L_CHILD(i)) {
            if ( (arr[i] < arr[R_CHILD(i)]) && (arr[R_CHILD(i)] > arr[L_CHILD(i)]) ) {
                swap(arr[i], arr[R_CHILD(i)]);
                i = R_CHILD(i);
            }
            else if ( (arr[i] < arr[L_CHILD(i)]) && (arr[L_CHILD(i)] > arr[R_CHILD(i)]) ) {
                swap(arr[i], arr[L_CHILD(i)]);
                i = L_CHILD(i);
            }
            else
                loop = false;
        }
        else
            loop = false;
    }
}

int extractMax() {
    if (size != 0) {
        int max = arr[1];

        arr[1] = arr[size];
        size--;

        sinkDown();
        return max;
    }
    return -1;
}

void insert(int n) {
    size++;

    if (size == 1) {
        arr = (int*)malloc(2*sizeof(int));
        arr[size] = n;
    }
    else {
        arr = (int*)realloc(arr, (size + 1)*sizeof(int));
        arr[size] = n;
        bubbleUp();
    }
}

void printArray() {
    int i;
    if (size != 0) {
        for (i = 1; i <= size; i++) {
            cout << arr[i] << ",";
        }
        cout << "\n";
    }
    else {
        cout << "Heap Empty !\n";
    }
}

int main(int argc, char const *argv[]) {
    // Test the functions here.
    return 0;
}
