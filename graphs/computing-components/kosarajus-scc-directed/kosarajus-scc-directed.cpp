#include <iostream>
#include <iterator>
#include <list>
#include <stdlib.h>

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

// We use recursion as means of stack, since recursion by itself is an stack operaton
void DFTUtil(list<int> adj_list[], bool visited[], int size, int start) {
    list<int>::iterator itr;

    visited[start] = true;
    cout << start << " ";

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

list<int>* reverseGraph(list<int> adj_list[], int size) {
    list<int> *rev_adj_list = new list<int>[size];
    list<int>::iterator itr;
    int i;

    for (i = 0; i < size; i++) {
        for (itr = adj_list[i].begin(); itr != adj_list[i].end(); itr++) {
            rev_adj_list[*itr].push_back(i);
        }
    }

    return rev_adj_list;
}

// Store in stack in order of finishing time
void firstPass(list<int> adj_list[], list<int> &stack, bool visited[], int size, int start) {
    list<int>::iterator itr;

    visited[start] = true;

    for (itr = adj_list[start].begin(); itr != adj_list[start].end(); itr++) {
        if (visited[*itr] == false)
            firstPass(adj_list, stack, visited, size, *itr);
    }

    stack.push_front(start);
}

void secondPass(list<int> adj_list[], int size) {
    int i;
    list<int> stack;
    bool* visited = (bool*)malloc(sizeof(bool)*size);

    for (i = 0; i < size; i++)
        visited[i] = false;

    // Call for first pass, here we store in stack
    firstPass(adj_list, stack, visited, size, 0);

    // Now reverse the graph so that source becomes sink
    adj_list = reverseGraph(adj_list, size);

    // Rsest the visited cache for second round of DFS
    for (i = 0; i < size; i++)
        visited[i] = false;

    // Now once reversal happens, then we can pop the stack and accordingly
    // use the sinks stored in stack for DFS and print them
    while (stack.size() > 0) {
        int vertex = stack.front();
        stack.pop_front();

        if (visited[vertex] == false) {
            DFTUtil(adj_list, visited, size, vertex);
            cout << "\n";
        }
    }
}

int main() {
    int size = 5;
    list<int> *adj_list = new list<int>[size];

    addEdge(adj_list, 2, 1);
    addEdge(adj_list, 1, 0);
    addEdge(adj_list, 0, 2);
    addEdge(adj_list, 0, 3);
    addEdge(adj_list, 3, 4);

    cout << "\nAdjacency Lists : \n";
    printGraph(adj_list, size);

    cout << "\nStrongly Conncted Components : \n";
    secondPass(adj_list, size);
}
