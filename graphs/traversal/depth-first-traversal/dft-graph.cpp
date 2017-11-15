#include <iostream>
#include <iterator>
#include <list>
#include <stdlib.h>

using namespace std;

// We use recursion as means of stack, since recursion by itself is an stack operaton
void DFTUtil(list<int> adj_list[], bool visited[], int size, int start) {
    list<int>::iterator itr;

    cout << start << " ";
    visited[start] = true;

    for (itr = adj_list[start].begin(); itr != adj_list[start].end(); itr++) {
        if (visited[*itr] == false)
            DFTUtil(adj_list, visited, size, *itr);
    }
}

void DFT(list<int> adj_list[], int size, int start) {
    int i;
    bool* visited = (bool*)malloc(sizeof(bool)*size);

    for (i = 0; i < size; i++)
        visited[i] = false;

    DFTUtil(adj_list, visited, size, start);
}

void addEdge(list<int> adj_list[], int firstV, int secondV) {
    adj_list[firstV].push_back(secondV);
    adj_list[secondV].push_back(firstV);
}

void printGraph(list<int> adj_list[], int size) {
    list<int>::iterator itr;

    int i;
    for (i = 0; i < size; i++) {
        cout << "\nV : " << i << " || ";
        for (itr = adj_list[i].begin(); itr != adj_list[i].end(); itr++) {
            cout << *itr << " ";
        }
    }
    cout << "\n";
}

int main() {
    int size = 6;
    list<int> *adj_list = new list<int>[size];

    addEdge(adj_list, 1, 3);
    addEdge(adj_list, 1, 4);
    addEdge(adj_list, 1, 5);
    addEdge(adj_list, 2, 0);
    addEdge(adj_list, 2, 5);
    addEdge(adj_list, 4, 3);
    addEdge(adj_list, 4, 2);

    cout << "\nAdjacency Lists : \n";
    printGraph(adj_list, size);

    cout << "\nTraversal Order :\n";
    DFT(adj_list, size, 3);
    cout << "\n";
}
