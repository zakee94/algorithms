#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <utility>
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

    if (v1 < size) {  // The check as mentioned above
        edge* E = (edge*)malloc(sizeof(edge));
        E->v2 = v1;
        E->length = length;

        adj_list[v2].push_back(E);
    }
    else
        cout << "\nERROR : Vertice value '" << v1 << "' exceeds that of graph size !\n";
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

void dijkstra(list<edge*> adj_list[], int size, int src) {
    set < pair<int, int> > setDist;
    list<edge*>::iterator itrEdge;

    int* dist = (int*)malloc(sizeof(int)*size);

    int i;
    for (i = 0; i < size; i++)
        dist[i] = INT_MAX;

    setDist.insert(make_pair(0, src));
    dist[src] = 0;

    while (!setDist.empty()) {
        pair<int, int> u = *(setDist.begin());
        setDist.erase(setDist.begin());

        for(itrEdge = adj_list[u.second].begin(); itrEdge != adj_list[u.second].end(); itrEdge++) {
            if (dist[u.second] + (*itrEdge)->length < dist[(*itrEdge)->v2]) {
                if(dist[(*itrEdge)->v2] != INT_MAX)
                    setDist.erase(setDist.find(make_pair(dist[(*itrEdge)->v2], (*itrEdge)->v2)));

                dist[(*itrEdge)->v2] = dist[u.second] + (*itrEdge)->length;
                setDist.insert(make_pair(dist[(*itrEdge)->v2], (*itrEdge)->v2));
            }
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
