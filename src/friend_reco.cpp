#include "GraphSTL.h"

// Example: friend recommendation (common friends in undirected graph)
int main() {
    Graph<string> g(false);

    g.addEdge("Shubham", "Mohit");
    g.addEdge("Mohit", "Nikhil");
    g.addEdge("Nikhil", "Jigyansh");
    g.addEdge("Shubham", "Chirag");

    cout << "BFS from Shubham: ";
    g.BFS("Shubham");

    cout << "Possible friends for Shubham shown by BFS traversal.\n";
    return 0;
}
