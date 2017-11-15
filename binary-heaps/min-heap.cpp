#include <iostream>
#include <stdlib.h>

using namespace std;
int size, *array;

#define L_CHILD(x) 2*x
#define R_CHILD(x) 2*x+1
#define PARENT(x) x/2

void bubbleUp() {
    int temp, i = size;
    bool flag = true;

    do {
        if (array[i] < array[PARENT(i)] && PARENT(i) != 0) {
            temp = array[PARENT(i)];
            array[PARENT(i)] = array[i];
            array[i] = temp;
        }
        else {
            flag = false;
        }
        i = PARENT(i);
    } while(flag);
}

void insert(int n) {
    size++;

    if (size == 1) {
        array = (int*)malloc(2*sizeof(int));
        array[1] = n;
    }
    else {
        array = (int*)realloc(array, (size+1)*sizeof(int));
        array[size] = n;
    }

    bubbleUp();
}

void sinkDown() {
    int temp, i = 1;
    bool flag = true;

    do {
        if ( (array[i] > array[R_CHILD(i)] || array[i] > array[L_CHILD(i)]) &&
                                    (size >= R_CHILD(i) || size >= L_CHILD(i)) ) {
            temp = array[i];
            if (array[R_CHILD(i)] < array[L_CHILD(i)]) {
                array[i] = array[R_CHILD(i)];
                array[R_CHILD(i)] = temp;
                i = R_CHILD(i);
            }
            else {
                array[i] = array[L_CHILD(i)];
                array[L_CHILD(i)] = temp;
                i = L_CHILD(i);
            }
        }
        else {
            flag = false;
        }
    } while(flag);
}

int extractMin() {
    int min;

    if (size != 0) {
        min = array[1];

        array[1] = array[size];
        size--;
        sinkDown();
    }
    else {
        cout << "Heap Empty !\n";
        min = -1729;
    }

    return min;
}

void printArray() {
    int i;
    if (size != 0) {
        for (i = 1; i <= size; i++) {
            cout << array[i] << ",";
        }
        cout << "\n";
    }
    else {
        cout << "Heap Empty !\n";
    }
}

int main() {
    // Test the functions here.
    return 0;
}
