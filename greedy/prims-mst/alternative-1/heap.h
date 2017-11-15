#include <stdlib.h>
#include <iostream>
#include <utility>

using namespace std;

#define PARENT(i) i/2
#define R_CHILD(i) (2*i)+1
#define L_CHILD(i) 2*i

int heapSize = 0;

struct Node {
    int vertice; // acts as key
    int value;
};
typedef struct Node node;

node *arr;

bool bubbleUp(int i) {
    int temp;
    bool bubbleUp = false;

    while((arr[i].value < arr[PARENT(i)].value) && (i > 1)) {
        swap(arr[i], arr[PARENT(i)]);
        i = PARENT(i);
        bubbleUp = true;
    }
    return bubbleUp;
}

bool sinkDown(int i) {
    bool loop = true, sinkDown = false;

    while(loop) {
        if ( (R_CHILD(i) <= heapSize) && (L_CHILD(i) > heapSize) ) {
            if (arr[i].value > arr[R_CHILD(i)].value) {
                swap(arr[i], arr[R_CHILD(i)]);
                i = R_CHILD(i);
                sinkDown = true;
            }
            else
                loop = false;
        }
        else if ( (L_CHILD(i) <= heapSize) && (R_CHILD(i) > heapSize) ) {
            if (arr[i].value > arr[L_CHILD(i)].value) {
                swap(arr[i], arr[L_CHILD(i)]);
                i = L_CHILD(i);
                sinkDown = true;
            }
            else
                loop = false;
        }
        else if ( (R_CHILD(i) <= heapSize) && (L_CHILD(i) <= heapSize) ) {
            if ( (arr[i].value > arr[R_CHILD(i)].value) && (arr[R_CHILD(i)].value < arr[L_CHILD(i)].value) ) {
                swap(arr[i], arr[R_CHILD(i)]);
                i = R_CHILD(i);
                sinkDown = true;
            }
            else if ( (arr[i].value > arr[L_CHILD(i)].value) && (arr[L_CHILD(i)].value < arr[R_CHILD(i)].value) ) {
                swap(arr[i], arr[L_CHILD(i)]);
                i = L_CHILD(i);
                sinkDown = true;
            }
            else
                loop = false;
        }
        else
            loop = false;
    }
    return sinkDown;
}

int extractMin() {
    if (heapSize != 0) {
        int min = arr[1].vertice;

        arr[1].vertice = arr[heapSize].vertice;
        arr[1].value = arr[heapSize].value;
        arr[heapSize].vertice = 0;;
        arr[heapSize].value = 0;
        heapSize--;

        sinkDown(1);
        return min;
    }
    else
        cout << "\nHeap Empty !\n";
    return -1;
}

void insert(int vertice, int value) {
    heapSize++;

    if (heapSize == 1) {
        arr = (node*)malloc(2*sizeof(node));
        arr[heapSize].vertice = vertice;
        arr[heapSize].value = value;
    }
    else {
        arr = (node*)realloc(arr, (heapSize + 1)*sizeof(node));
        arr[heapSize].vertice = vertice;
        arr[heapSize].value = value;
        bubbleUp(heapSize);
    }
}

bool update(int vertice, int value) {
    int i;
    bool update = false;

    for (i = 1; i <= heapSize; i++) {
        if (arr[i].vertice == vertice && arr[i].value > value) {
            arr[i].value = value;
            if (!bubbleUp(i))
                sinkDown(i);
            update = true;
        }
    }
    return update;
}

void printArray() {
    int i;
    if (heapSize != 0) {
        for (i = 1; i <= heapSize; i++) {
            cout << arr[i].vertice << "," << arr[i].value << " | ";
        }
        cout << "\n";
    }
    else {
        cout << "Heap Empty !\n";
    }
}

// Example main() function for function testing
/*int main(int argc, char const *argv[]) {
    insert(1,10);insert(2,9);insert(3,-11);insert(4,1);
    insert(5,101);insert(6,-10);insert(7,71);insert(8,-99);
    printArray();
    //
    update(1, 112);printArray();
    update(2, -12);printArray();
    update(-12, 99);printArray();
    update(3, -99);printArray();
    //
    cout << extractMin() << "\n";
    cout << extractMin() << "\n";
    cout << extractMin() << "\n";
    cout << extractMin() << "\n";
    cout << extractMin() << "\n";
    cout << extractMin() << "\n";
    cout << extractMin() << "\n";
    cout << extractMin() << "\n";
    cout << extractMin() << "\n";

    return 0;
}*/
