#include <iostream>
#include <iterator>
#include <list>
#include <stdlib.h>

using namespace std;

struct edge {
    int v2;
    int length;
};
// Note that v2 can take ANY values, even vertices that are greater
// than the size of the graph, hence note that size is passed in addEdge()
// to ensure a check, otherwise segmentation fault can happen.

// Alternatively one can impleent this check while taking input, thus no need to
// pass size in addEdge().

typedef struct edge edge;

void addEdge(list<edge*> adj_list[], int size, int v1, int v2, int length) {
    edge* E = (edge*)malloc(sizeof(edge));

    if (v2 < size) {  // The check as mentioned above
        E->v2 = v2;
        E->length = length;

        adj_list[v1].push_back(E);
    }
    else
        cout << "\nERROR : Vertice value '" << v2 << "' exceeds that of graph size !\n";

}

void printGraph(list<edge*> adj_list[], int size) {
    list<edge*>::iterator itr;

    int i;
    for (i = 0; i < size; i++) {
        cout << "\nV : " << i << " || ";
        for (itr = adj_list[i].begin(); itr != adj_list[i].end(); itr++)
            cout << "(" << (*itr)->v2 << ", " << (*itr)->length << ") ; ";
    }
    cout << "\n";
}

int main() {
    int size = 3;
    list<edge*>* adj_list = new list<edge*>[size];

    addEdge(adj_list, size, 0, 1, 1);
    addEdge(adj_list, size, 0, 2, 3);
    addEdge(adj_list, size, 1, 2, 5);
    printGraph(adj_list, size);
}
