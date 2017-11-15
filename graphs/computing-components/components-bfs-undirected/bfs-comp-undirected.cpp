#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <stdlib.h>

using namespace std;

void BFTUtil(list<int> adj_list[], bool visited[], int size, int start) {
    list<int>::iterator itr;
    list<int> queue;
    int curr_vertex;

    queue.push_back(start);
    visited[start] = true;

    cout << "\nTraversal Order :\n";
    while(queue.size() != 0) {
        curr_vertex = queue.front();
        queue.pop_front();
        cout << curr_vertex << " ";
        for (itr = adj_list[curr_vertex].begin(); itr != adj_list[curr_vertex].end(); itr++) {
            if (visited[*itr] == false) {
                queue.push_back(*itr);
                visited[*itr] = true;
            }
        }
    }
}

void calcComponents(list<int> adj_list[], int size) {
    int i, components = 0;
    bool* visited = (bool*)malloc(sizeof(bool)*size);

    for (i = 0; i < size; i++)
        visited[i] = false;

    for (i = 0; i < size; i++) {
        if (visited[i] == false) {
            components++;
            BFTUtil(adj_list, visited, size, i);
        }
    }

    cout << "\n\nComponents : " << components << "\n";
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
    int size = 10;
    list<int> *adj_list = new list<int>[size];

    addEdge(adj_list, 1, 3);
    addEdge(adj_list, 1, 5);
    addEdge(adj_list, 3, 5);
    addEdge(adj_list, 7, 5);
    addEdge(adj_list, 2, 4);
    addEdge(adj_list, 9, 5);
    addEdge(adj_list, 6, 8);
    addEdge(adj_list, 8, 0);
    addEdge(adj_list, 6, 0);

    cout << "\nAdjacency Lists : \n";
    printGraph(adj_list, size);

    calcComponents(adj_list, size);
}
