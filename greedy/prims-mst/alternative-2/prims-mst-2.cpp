#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <limits.h>

using namespace std;

struct edge {
    int v2;
    int length;
};
typedef struct edge edge;

struct parentVertice {
	int parent;
	int edgeCost;
};
typedef struct parentVertice pv;

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

void primsMST(list<edge*> adj_list[], int size, int src) {
    multimap < int, int > minMap;
    multimap<int,int>::iterator itrMap, itrMapIn;

    list<edge*>::iterator itrEdge;
    pv *pvArr = new pv[size];
    int i;

    for (i = 0; i < size; i++) {
        if (i != src)
            minMap.insert(pair<int,int>(INT_MAX, i));
        else
            minMap.insert(pair<int,int>(0, i));
    }

    while (!minMap.empty()) {
        itrMap = minMap.begin();
        minMap.erase(itrMap);

        //cout << itrMap->second << "\n";
        for(itrEdge = adj_list[itrMap->second].begin(); itrEdge != adj_list[itrMap->second].end(); itrEdge++) {
            for (itrMapIn = minMap.begin(); itrMapIn != minMap.end(); itrMapIn++) {
                if ( (itrMapIn->second == (*itrEdge)->v2) && ((*itrEdge)->length < itrMapIn->first) ) {
                    minMap.erase(itrMapIn);
                    minMap.insert(pair<int,int>((*itrEdge)->length, (*itrEdge)->v2));
                    //
                    pvArr[(*itrEdge)->v2].parent = itrMap->second;
        			pvArr[(*itrEdge)->v2].edgeCost = (*itrEdge)->length;
                    //
                    break;
                }
            }
        }
    }

    for (i = 1; i < size; i++)
    	cout << i << "-" << pvArr[i].parent << "," << pvArr[i].edgeCost << "\n";

    delete []pvArr;
}

int main() {
    int size = 9;
    list<edge*>* adj_list = new list<edge*>[size];

    addEdge(adj_list, size, 0, 1, 4);
    addEdge(adj_list, size, 0, 7, 8);
    addEdge(adj_list, size, 1, 2, 8);
    addEdge(adj_list, size, 1, 7, 11);
    addEdge(adj_list, size, 2, 3, 7);
    addEdge(adj_list, size, 2, 8, 2);
    addEdge(adj_list, size, 2, 5, 4);
    addEdge(adj_list, size, 3, 4, 9);
    addEdge(adj_list, size, 3, 5, 14);
    addEdge(adj_list, size, 4, 5, 10);
    addEdge(adj_list, size, 5, 6, 2);
    addEdge(adj_list, size, 6, 7, 1);
    addEdge(adj_list, size, 6, 8, 6);
    addEdge(adj_list, size, 7, 8, 7);

    primsMST(adj_list, size, 0);
}
