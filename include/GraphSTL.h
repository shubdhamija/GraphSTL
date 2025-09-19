#ifndef GRAPHSTL_H
#define GRAPHSTL_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <string>
#include <utility>
using namespace std;

template <typename T>
class Graph {
    unordered_map<T, vector<pair<T, int>>> adj;
    bool directed;

public:
    Graph(bool isDirected = false) : directed(isDirected) {}

    // 1. Add Edge
    void addEdge(T u, T v, int w = 1) {
        adj[u].push_back({v, w});
        if (!directed) adj[v].push_back({u, w});
    }

    // 2. BFS
    void BFS(T start) {
        unordered_map<T, bool> visited;
        queue<T> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            T node = q.front(); q.pop();
            cout << node << " ";
            for (auto [nbr, wt] : adj[node]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        cout << endl;
    }

    // 3. DFS
    void DFS(T start) {
        unordered_map<T, bool> visited;
        DFSUtil(start, visited);
        cout << endl;
    }

    // 4. Topological Sort
    void topologicalSort() {
        unordered_map<T, bool> visited;
        stack<T> st;
        for (auto &p : adj) {
            if (!visited[p.first]) topoUtil(p.first, visited, st);
        }
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }

    // 5. Cycle Detection (directed)
    bool hasCycle() {
        unordered_map<T, bool> visited, recStack;
        for (auto &p : adj) {
            if (!visited[p.first] && isCyclicUtil(p.first, visited, recStack))
                return true;
        }
        return false;
    }

    // 6–8. Shortest Path (auto decides)
    void shortestPath(T src) {
        if (!directed) {
            shortestPathUndirected(src);
        } else if (!hasCycle()) {
            shortestPathDAG(src);
        } else {
            dijkstra(src);
        }
    }

private:
    void DFSUtil(T node, unordered_map<T, bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        for (auto [nbr, wt] : adj[node]) {
            if (!visited[nbr]) DFSUtil(nbr, visited);
        }
    }

    void topoUtil(T node, unordered_map<T, bool>& visited, stack<T>& st) {
        visited[node] = true;
        for (auto [nbr, wt] : adj[node]) {
            if (!visited[nbr]) topoUtil(nbr, visited, st);
        }
        st.push(node);
    }

    bool isCyclicUtil(T node, unordered_map<T, bool>& visited,
                      unordered_map<T, bool>& recStack) {
        visited[node] = recStack[node] = true;
        for (auto [nbr, wt] : adj[node]) {
            if (!visited[nbr] && isCyclicUtil(nbr, visited, recStack)) return true;
            else if (recStack[nbr]) return true;
        }
        recStack[node] = false;
        return false;
    }

    void shortestPathUndirected(T src) {
        unordered_map<T, int> dist;
        for (auto &p : adj) dist[p.first] = INT_MAX;
        queue<T> q;
        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            T node = q.front(); q.pop();
            for (auto [nbr, wt] : adj[node]) {
                if (dist[nbr] == INT_MAX) {
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }
        for (auto [node, d] : dist)
            cout << "Dist(" << src << "->" << node << ")=" << d << endl;
    }

    void shortestPathDAG(T src) {
        unordered_map<T, bool> visited;
        stack<T> st;
        for (auto &p : adj) {
            if (!visited[p.first]) topoUtil(p.first, visited, st);
        }
        unordered_map<T, int> dist;
        for (auto &p : adj) dist[p.first] = INT_MAX;
        dist[src] = 0;

        while (!st.empty()) {
            T node = st.top(); st.pop();
            if (dist[node] != INT_MAX) {
                for (auto [nbr, wt] : adj[node]) {
                    if (dist[node] + wt < dist[nbr])
                        dist[nbr] = dist[node] + wt;
                }
            }
        }
        for (auto [node, d] : dist)
            cout << "Dist(" << src << "->" << node << ")=" << d << endl;
    }

    void dijkstra(T src) {
        unordered_map<T, int> dist;
        for (auto &p : adj) dist[p.first] = INT_MAX;
        using P = pair<int, T>;
        priority_queue<P, vector<P>, greater<P>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();
            if (d > dist[node]) continue;

            for (auto [nbr, wt] : adj[node]) {
                if (dist[node] + wt < dist[nbr]) {
                    dist[nbr] = dist[node] + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        for (auto [node, d] : dist)
            cout << "Dist(" << src << "->" << node << ")=" << d << endl;
    }
};

#endif // GRAPHSTL_H
