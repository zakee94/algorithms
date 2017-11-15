#include <iostream>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

void addEdge(list<int> adj_list[], int firstV, int secondV) {
    adj_list[firstV].push_back(secondV);
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

    addEdge(adj_list, 3, 1);
    addEdge(adj_list, 3, 4);
    addEdge(adj_list, 1, 4);
    addEdge(adj_list, 2, 4);
    addEdge(adj_list, 2, 5);
    addEdge(adj_list, 0, 2);
    addEdge(adj_list, 5, 1);

    cout << "\nAdjacency Lists : \n";
    printGraph(adj_list, size);
}
