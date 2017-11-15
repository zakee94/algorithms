#include <iostream>
#include <list>
#include <iterator>
#include <stdlib.h>

using namespace std;

// here we shall use an array of only modest sze 997(prime no), and
// for collisions we will be using list implementation.
// so basically we get an adjacency list type of implementation

int hashFunction(int n) {
    return (abs(n) % 997);
}

void deleteElement(list<int> array[], int n) {
    list<int>::iterator itr;
    int i = hashFunction(n);

    for (itr = array[i].begin(); itr != array[i].end(); itr++) {
        if(n == *itr) {
            array[i].remove(n);
            cout << "Erased " << n << "\n";
            break;
        }
    }
}

int lookUp(list<int> array[], int n) {
    list<int>::iterator itr;
    int i = hashFunction(n);

    for (itr = array[i].begin(); itr != array[i].end(); itr++) {
        if(n == *itr) {
            cout << "Found at index : " << i << "\n";
            return 1;
        }
    }
    return 0;
}

void insert(list<int> array[], int n) {
    if (!lookUp(array, n))
        array[hashFunction(n)].push_back(n);
    else
        cout << "Duplicate Value !\n";
}

void printTable(list<int> array[]) {
    list<int>::iterator itr;
    int i;

    for (i = 0; i < 997; i++) {
        cout << "\nIndex : " << i << " || ";
        for (itr = array[i].begin(); itr != array[i].end(); itr++) {
            cout << *itr << " ";
        }
    }
    cout << "\n";
}

int main() {
    list<int> *array = new list<int>[997];

    insert(array, 52569);
    insert(array, -52569);
    insert(array, -52569);
    lookUp(array, -52569);
    deleteElement(array, -52569);
    printTable(array);
}
