# DFS on Graph Template

## Overview

Graph DFS is the same depth-first idea as tree DFS, with one essential addition:
track visited nodes to avoid revisiting nodes in cycles.

Core pattern:

1. Mark current node as visited.
2. Iterate neighbors.
3. Recurse only into unvisited neighbors.

## When to Use DFS on Graphs

- Traverse all reachable nodes from a start node
- Check if a path exists between two nodes
- Find connected components
- Detect cycles (with extra state in directed graphs)
- Build traversal order for further processing

## Node-Based Recursive Template

```cpp
#include <unordered_set>
#include <vector>

template <typename T>
struct Node {
    T val;
    std::vector<Node*> neighbors;
};

template <typename T>
void dfs(Node<T>* node, std::unordered_set<Node<T>*>& visited) {
    if (node == nullptr) return;
    if (visited.count(node)) return;

    visited.insert(node);

    for (Node<T>* neighbor : node->neighbors) {
        if (!visited.count(neighbor)) {
            dfs(neighbor, visited);
        }
    }
}
```

Typical call:

```cpp
std::unordered_set<Node<int>*> visited;
dfs(start, visited);
```

## Adjacency List Template (Common in Interviews)

```cpp
#include <unordered_set>
#include <vector>

void dfs(int node, const std::vector<std::vector<int>>& graph,
         std::unordered_set<int>& visited) {
    if (visited.count(node)) return;
    visited.insert(node);

    for (int neighbor : graph[node]) {
        if (!visited.count(neighbor)) {
            dfs(neighbor, graph, visited);
        }
    }
}
```

## Iterative DFS Template (Stack-Based)

Use iterative DFS when recursion depth may be large and risk stack overflow.

Node-based version:

```cpp
#include <stack>
#include <unordered_set>

template <typename T>
void dfsIterative(Node<T>* start, std::unordered_set<Node<T>*>& visited) {
    if (start == nullptr) return;

    std::stack<Node<T>*> st;
    st.push(start);

    while (!st.empty()) {
        Node<T>* node = st.top();
        st.pop();

        if (visited.count(node)) continue;
        visited.insert(node);

        // Push neighbors to continue depth-first exploration.
        for (Node<T>* neighbor : node->neighbors) {
            if (!visited.count(neighbor)) {
                st.push(neighbor);
            }
        }
    }
}
```

Adjacency-list version:

```cpp
#include <stack>
#include <unordered_set>
#include <vector>

void dfsIterative(int start, const std::vector<std::vector<int>>& graph,
                  std::unordered_set<int>& visited) {
    std::stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (visited.count(node)) continue;
        visited.insert(node);

        for (int neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                st.push(neighbor);
            }
        }
    }
}
```

Note: traversal order in iterative DFS depends on neighbor push order.

## Recursive vs Iterative DFS

| Aspect | Recursive DFS | Iterative DFS |
|---|---|---|
| Readability | Usually shorter and easier to write | Slightly more boilerplate (explicit stack) |
| Stack safety | Can overflow call stack on deep graphs | Safer for deep traversals |
| Traversal order control | Implicit via recursion + neighbor order | Explicit via push order on stack |
| Memory model | Uses call stack | Uses heap-allocated container (`std::stack`) |
| Interview speed | Fast to draft | Better when interviewer asks about large depth |

Rule of thumb:

- Use recursive DFS for clarity when depth is manageable.
- Use iterative DFS when depth can be very large.

## Path Existence Template

```cpp
bool hasPath(int src, int dst, const std::vector<std::vector<int>>& graph,
             std::unordered_set<int>& visited) {
    if (src == dst) return true;
    if (visited.count(src)) return false;

    visited.insert(src);
    for (int nxt : graph[src]) {
        if (hasPath(nxt, dst, graph, visited)) {
            return true;
        }
    }
    return false;
}
```

## Connected Components Template

```cpp
int countComponents(const std::vector<std::vector<int>>& graph) {
    int n = static_cast<int>(graph.size());
    std::unordered_set<int> visited;
    int components = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited.count(i)) {
            ++components;
            dfs(i, graph, visited);
        }
    }
    return components;
}
```

## Complexity

For graph with V vertices and E edges (adjacency list):

- Time: O(V + E)
- Space: O(V) for visited + recursion stack (worst-case O(V))

## Common Mistakes

- Forgetting visited checks before recursion (infinite recursion on cycles)
- Marking visited too late (can cause duplicate work)
- Running DFS from only one node when full graph traversal is needed
- Confusing tree logic with graph logic (graphs can have cycles and multiple parents)

## Quick Mental Checklist

- What uniquely identifies a node (index, pointer, id)?
- When do I mark visited (before exploring neighbors)?
- Do I need traversal from one source or all nodes?
- Does the problem need boolean existence, counting, or full traversal output?
