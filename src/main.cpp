#include "GraphSTL.h"

int main() {
    Graph<int> g(false); // undirected graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    cout << "BFS from 0: ";
    g.BFS(0);

    cout << "DFS from 0: ";
    g.DFS(0);

    cout << "Shortest paths from 0:\n";
    g.shortestPath(0);

    return 0;
}
