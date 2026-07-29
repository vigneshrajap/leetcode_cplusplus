# BFS on Graph Template

## Overview

Breadth First Search (BFS) on graphs explores nodes in layers (distance from start).
Compared with tree BFS, we add one key mechanism: `visited` to prevent revisiting nodes in cycles.

Core pattern:

1. Initialize queue with start node.
2. Mark start as visited.
3. Pop front node.
4. Push each unvisited neighbor and mark visited.
5. Repeat until queue is empty.

## Tree vs Graph BFS

- Tree: no cycles, so visited is usually unnecessary.
- Graph: cycles may exist, so visited is required.
- Best practice: mark visited when enqueuing, not when dequeuing.

## When to Use BFS on Graphs

- Find shortest path in an unweighted graph (fewest edges)
- Find minimum moves/steps problems
- Traverse all reachable nodes from a source
- Find connected components (undirected graphs)
- Multi-source expansion problems

## Node-Based BFS Template

```cpp
#include <queue>
#include <unordered_set>
#include <vector>

template <typename T>
struct Node {
    T val;
    std::vector<Node*> neighbors;
};

template <typename T>
void bfs(Node<T>* start, std::unordered_set<Node<T>*>& visited) {
    if (start == nullptr) return;

    std::queue<Node<T>*> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        Node<T>* node = q.front();
        q.pop();

        for (Node<T>* neighbor : node->neighbors) {
            if (neighbor != nullptr && !visited.count(neighbor)) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}
```

## Adjacency List BFS Template (Most Common)

```cpp
#include <queue>
#include <unordered_set>
#include <vector>

void bfs(int start, const std::vector<std::vector<int>>& graph,
         std::unordered_set<int>& visited) {
    std::queue<int> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}
```

## Shortest Path Length in Unweighted Graph

BFS guarantees first visit to a node is the shortest distance (by edge count).

```cpp
#include <queue>
#include <vector>

int shortestPathLen(int src, int dst, const std::vector<std::vector<int>>& graph) {
    int n = static_cast<int>(graph.size());
    std::vector<int> dist(n, -1);

    std::queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == dst) return dist[node];

        for (int neighbor : graph[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return -1;  // unreachable
}
```

## Level (Distance Layer) Traversal Template

Use this when you need all nodes by distance from start.

```cpp
#include <queue>
#include <unordered_set>
#include <vector>

std::vector<std::vector<int>> bfsLayers(int start,
                                        const std::vector<std::vector<int>>& graph) {
    std::vector<std::vector<int>> layers;
    std::unordered_set<int> visited;
    std::queue<int> q;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int layerSize = static_cast<int>(q.size());
        std::vector<int> layer;
        layer.reserve(layerSize);

        for (int i = 0; i < layerSize; ++i) {
            int node = q.front();
            q.pop();
            layer.push_back(node);

            for (int neighbor : graph[node]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        layers.push_back(std::move(layer));
    }

    return layers;
}
```

## Connected Components (Undirected Graph)

```cpp
int countComponents(const std::vector<std::vector<int>>& graph) {
    int n = static_cast<int>(graph.size());
    std::unordered_set<int> visited;
    int components = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited.count(i)) {
            ++components;
            bfs(i, graph, visited);
        }
    }

    return components;
}
```

## Complexity

For adjacency-list graph with V vertices and E edges:

- Time: O(V + E)
- Space: O(V) for visited + queue in worst case

## Common Mistakes

- Forgetting visited tracking in cyclic graphs
- Marking visited after dequeue (can enqueue duplicates)
- Using BFS on weighted shortest-path problems (use Dijkstra when weights are non-uniform)
- Starting from only one source when problem asks full-graph result
- Confusing tree assumptions with graph reality (multiple parents/cycles)

## Quick Mental Checklist

- Is the graph unweighted and shortest-by-edges needed? (Prefer BFS)
- Did I mark visited at enqueue time?
- Do I need one source or all sources?
- For step/level questions, did I process by queue size per layer?
