GraphSTL — Mini Graph Algorithms Library

GraphSTL is a header-only C++17 library that provides common graph data structures and algorithms in a simple and reusable way.
It is designed to help beginners, students, and developers quickly experiment with graph algorithms without writing boilerplate code from scratch.

📦 What’s Inside?

GraphSTL currently supports:

✅ Graph creation using addEdge (directed/undirected, weighted/unweighted)

✅ Traversals: Breadth-First Search (BFS) and Depth-First Search (DFS)

✅ Topological Sort (for directed acyclic graphs)

✅ Cycle Detection (in directed graphs)

✅ Shortest Path Algorithms:

BFS shortest path for unweighted graphs

Relaxation-based shortest path for DAGs

Dijkstra’s Algorithm for weighted graphs

🔑 Key Features

Header-only → just include GraphSTL.h in your project

Template-based → works with int, string, or even custom key types

Auto-selection of shortest path algorithm → you don’t need to manually choose

Lightweight & Easy to Learn → ideal for DSA practice, interviews, and academic projects

Ready-made examples → included demos for:

📘 Basic graph usage

👥 Friend recommendation (social graph use case)

📅 Task scheduler (topological sorting)

🚀 Getting Started
1. Clone the Repository
git clone https://github.com/<your-username>/GraphSTLDemo.git
cd GraphSTLDemo

2. Build with CMake (Recommended)
mkdir build
cd build
cmake ..
cmake --build .


After building, you’ll find executables in build/:

graph_basic

friend_reco

task_scheduler

Run one:

./graph_basic

📖 Example Usage

Here’s a minimal program using GraphSTL:

#include "GraphSTL.h"

int main() {
    // Create an undirected graph with int nodes
    Graph<int> g(false);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    cout << "BFS starting from node 0: ";
    g.BFS(0);

    cout << "\nShortest paths from node 0:\n";
    g.shortestPath(0);

    return 0;
}

Compile manually without CMake
g++ temp.cpp -Iinclude -o temp
./temp

🎥 Demo Video

Watch the usage demo on YouTube:


📂 Project Structure
GraphSTLDemo/
├─ include/
│  └─ GraphSTL.h          # The library (header-only)
├─ src/
│  ├─ main.cpp             # Basic graph usage demo
│  ├─ friend_reco.cpp      # Friend recommendation demo
│  └─ task_scheduler.cpp   # Task scheduling demo
├─ CMakeLists.txt          # Build script for CMake
├─ README.md               # This file
├─ LICENSE                 # MIT License
└─ .gitignore              # Ignored files (build artifacts etc.)

💡 Use Cases

Some example applications of GraphSTL:

Social Networks → friend recommendation using graph traversal

Project Planning → task scheduling with topological sort

Navigation Systems → shortest path algorithms for routes

Computer Science Education → easy to learn BFS, DFS, Dijkstra

Competitive Programming → quick plug-and-play graph utilities

🤝 Contributing

Contributions are welcome!
If you find bugs or want to add new algorithms (like Kruskal, Prim, or Floyd–Warshall), open an issue or PR.