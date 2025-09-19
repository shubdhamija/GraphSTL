#include <iostream>
#include "GraphSTL.h"
using namespace std;

int main() {
    Graph<string> g(true); // directed graph

    // Tasks (edges mean dependency)
    g.addEdge("Design", "Coding");
    g.addEdge("Coding", "Testing");
    g.addEdge("Testing", "Deployment");

    cout << "Task order (Topological Sort):\n";
    g.topologicalSort();
}
