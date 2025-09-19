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

There are three ways to use GraphSTL locally in your C++ projects.

1️⃣ Header-Only Include (Recommended for beginners)

1 - Since GraphSTL is header-only, you don’t need to build the library.

2 - Download GraphSTL.h from this repository.

3 - Place it inside an include folder in your project directory.

4 - Include it in your C++ file

Exmaple:-
```cpp
#include "GraphSTL.h"
int main() {
    Graph<int> g(false); // undirected
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    g.BFS(0);
    g.shortestPath(0);
    return 0;
}
```

5 - Folder structure example:
```
MyProject/
├─ include/
│  └─ GraphSTL.h
└─ temp.cpp
```

6 - Compile and run manually:
```bash
g++ temp.cpp -Iinclude -o temp.exe
./temp.exe
```

2️⃣ Using CMake (for multi-file projects)

 i) - You can include GraphSTL in larger projects using CMake.
 
ii) - Folder structure:
```
MyProject/
├─ CMakeLists.txt
├─ include/
│  └─ GraphSTL.h
└─ src/
   └─ main.cpp
```


iii) - CMakeLists.txt example:

```txt
cmake_minimum_required(VERSION 3.15)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(main src/main.cpp)
```


iv) - Build and run:
``` bash
mkdir build
cd build
cmake ..
cmake --build .
```


v) - Executables will appear in 
``` bash
build/Debug/ (Windows)/
build/ (Linux/macOS).
```

vi) -  Run:
``` bash
./Debug/main.exe   # Windows
./main             # Linux/macOS
```

📂 Project Structure
```
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
```

💡 Use Cases
Some example applications of GraphSTL:

1. Network & Route Planning → Model transportation, logistics, or communication networks. 
   Find shortest paths, optimal routes, and analyze connectivity (e.g., metro systems, delivery networks, or data networks).

2. Social Networks → Friend recommendation and connection analysis using graph traversal algorithms.

3. Project Planning → Task scheduling and dependency resolution with topological sorting.

4. Navigation Systems → Finding shortest paths in maps or virtual environments using BFS, DAG relaxation, or Dijkstra.

5. Computer Science Education → Learn and practice fundamental graph algorithms like BFS, DFS, and shortest path algorithms.

6. Competitive Programming → Quick plug-and-play graph utilities for contests and coding interviews.

🤝 Contributing

Contributions are welcome!
If you find bugs or want to add new algorithms (like Kruskal, Prim, or Floyd–Warshall), open an issue or PR.
