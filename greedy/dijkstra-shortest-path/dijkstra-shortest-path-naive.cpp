// This is a naive implementation of Dijkstra's Algorithm without using heap
// and gives a time complexity of O(mn).
#include <iostream>
#include <iterator>
#include <list>
#include <stdlib.h>
#include <limits.h>

using namespace std;

struct edge {
    int v2;
    int length;
};

typedef struct edge edge;

void addEdge(list<edge*> adj_list[], int size, int v1, int v2, int length) {
    edge* E = (edge*)malloc(sizeof(edge));

    if (v2 < size) {
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

int minimum(bool prcsVer[], int dist[], int size) {
    int i, min = INT_MAX, min_index;

    for (i = 0; i < size; i++) {
        if (prcsVer[i] == false && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void dijkstra(list<edge*> adj_list[], int size, int src) {
    bool* prcsVer = (bool*)malloc(sizeof(bool)*size); // prcsVer = processedVertices
    int* dist = (int*)malloc(sizeof(int)*size);

    list<edge*>::iterator itr;
    int i, n = 0;
    for (i = 0; i < size; i++) { // Initialize distance and processedVertices
        prcsVer[i] = false;
        dist[i] = INT_MAX;
    }

    dist[src] = 0;          // Source distance is always 0

    while (n < size) {
        // Select minimum from all those vertices whose dist is calculated but
        // is yet not processed
        int min_index = minimum(prcsVer, dist, size);
        prcsVer[min_index] = true;
        n++;

        // Now using that minimum get dist of its adjacent vertices
        for (itr = adj_list[min_index].begin(); itr != adj_list[min_index].end(); itr++) {
            // Carefully note the second part of 'if' after '&&', that check is only useful in case of parallel
            // edges, if already a minimum dist is found then no need to update the value, i.e,
            // if length(edge2) > length(edge1), then don't update value
            if (prcsVer[(*itr)->v2] == false && (dist[min_index] + (*itr)->length) < dist[(*itr)->v2])
                dist[(*itr)->v2] = dist[min_index] + (*itr)->length;
        }
    }

    for (i = 0; i < size; i++)
        cout << i << " --> " << dist[i] << "\n";
}

int main() {
    int size = 4;
    list<edge*>* adj_list = new list<edge*>[size];

    addEdge(adj_list, size, 0, 1, 1);
    addEdge(adj_list, size, 0, 2, 4);
    addEdge(adj_list, size, 1, 2, 2);
    addEdge(adj_list, size, 1, 2, 4);
    addEdge(adj_list, size, 1, 2, 1);
    addEdge(adj_list, size, 1, 3, 6);
    addEdge(adj_list, size, 2, 3, 3);
    
    cout << "\nAdjacency List :\n";
    printGraph(adj_list, size);

    dijkstra(adj_list, size, 0);
}
