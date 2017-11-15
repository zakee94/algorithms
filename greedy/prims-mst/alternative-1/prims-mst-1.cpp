#include </home/zakee94/Junkyard/algorithms/greedy/prims-mst/heap.h>
#include <//home/zakee94/Junkyard/algorithms/greedy/prims-mst/graph.h>
#include <iterator>
#include <list>
#include <limits.h>

using namespace std;

struct parentVertice {
	int parent;
	int edgeCost;
};
typedef struct parentVertice pv;

void initHeap(int graphSize) {
    int i;
    for (i = 0; i < graphSize; i++)
        insert(i, INT_MAX);
    // We start with 0 vertex and init it's dist as 0
    update(0, 0);
}

void primsMST(list<edge*> adj_list[], int graphSize) {
    initHeap(graphSize);
    pv *pvArr = new pv[graphSize];

    while (heapSize != 0) {
    	int vertice;
    	vertice = extractMin();

    	list<edge*>::iterator itr;
    	for (itr = adj_list[vertice].begin(); itr != adj_list[vertice].end(); itr++) {
    		if (update((*itr)->v2, (*itr)->length)) {
    			pvArr[(*itr)->v2].parent = vertice;
    			pvArr[(*itr)->v2].edgeCost = (*itr)->length;
    		}
    	}
    }
    int i;
    for (i = 1; i < graphSize; i++)
    	cout << i << "-" << pvArr[i].parent << "," << pvArr[i].edgeCost << "\n";

    delete []pvArr;
}

int main(int argc, char const *argv[]) {
    int graphSize = 9;
    list<edge*>* adj_list = new list<edge*>[graphSize];

    addEdge(adj_list, graphSize, 0, 1, 4);
    addEdge(adj_list, graphSize, 0, 7, 8);
    addEdge(adj_list, graphSize, 1, 2, 8);
    addEdge(adj_list, graphSize, 1, 7, 11);
    addEdge(adj_list, graphSize, 2, 3, 7);
    addEdge(adj_list, graphSize, 2, 8, 2);
    addEdge(adj_list, graphSize, 2, 5, 4);
    addEdge(adj_list, graphSize, 3, 4, 9);
    addEdge(adj_list, graphSize, 3, 5, 14);
    addEdge(adj_list, graphSize, 4, 5, 10);
    addEdge(adj_list, graphSize, 5, 6, 2);
    addEdge(adj_list, graphSize, 6, 7, 1);
    addEdge(adj_list, graphSize, 6, 8, 6);
    addEdge(adj_list, graphSize, 7, 8, 7);

    primsMST(adj_list, graphSize);

    return 0;
}
