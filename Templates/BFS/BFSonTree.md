# BFS on Tree Template

## Overview

Breadth First Search (BFS) visits nodes level by level.
Unlike DFS (which goes deep first), BFS explores all nodes at depth d before depth d + 1.

Core idea:

1. Use a queue (FIFO).
2. Dequeue one node.
3. Enqueue its children.
4. Repeat until queue is empty.

## DFS vs BFS (Rule of Thumb)

- DFS is often better when the answer may be deep in a branch.
- BFS is often better when the answer is near the root.
- BFS gives shortest path in unweighted tree/graph by number of edges.

## Basic BFS Template (Early Return Search)

```cpp
#include <queue>
#include <vector>

template <typename T>
struct Node {
    T val;
    std::vector<Node*> children;
};

template <typename T>
Node<T>* bfsFind(Node<T>* root, const T& target) {
    if (root == nullptr) return nullptr;

    std::queue<Node<T>*> q;
    q.push(root);  // kick-start BFS with one node

    while (!q.empty()) {
        Node<T>* node = q.front();
        q.pop();

        if (node->val == target) return node;  // early return

        for (Node<T>* child : node->children) {
            if (child != nullptr) {
                q.push(child);
            }
        }
    }

    return nullptr;
}
```

## Level Order Traversal Template

Use this pattern when the problem asks for level-by-level output.

```cpp
#include <queue>
#include <vector>

template <typename T>
std::vector<std::vector<T>> levelOrder(Node<T>* root) {
    std::vector<std::vector<T>> ans;
    if (root == nullptr) return ans;

    std::queue<Node<T>*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = static_cast<int>(q.size());
        std::vector<T> level;
        level.reserve(levelSize);

        for (int i = 0; i < levelSize; ++i) {
            Node<T>* node = q.front();
            q.pop();
            level.push_back(node->val);

            for (Node<T>* child : node->children) {
                if (child != nullptr) q.push(child);
            }
        }

        ans.push_back(std::move(level));
    }

    return ans;
}
```

## Min Depth Template (Classic BFS Use Case)

BFS naturally finds the minimum depth because first leaf reached is the shallowest.

```cpp
template <typename T>
int minDepth(Node<T>* root) {
    if (root == nullptr) return 0;

    std::queue<std::pair<Node<T>*, int>> q;
    q.push({root, 1});

    while (!q.empty()) {
        auto [node, depth] = q.front();
        q.pop();

        bool isLeaf = node->children.empty();
        if (isLeaf) return depth;

        for (Node<T>* child : node->children) {
            if (child != nullptr) q.push({child, depth + 1});
        }
    }

    return 0;
}
```

## Complexity

For a tree with n nodes:

- Time: O(n), each node is dequeued once.
- Space: O(w), where w is max width of the tree (worst-case O(n)).

## Common Mistakes

- Forgetting the null-root check.
- Using wrong variable names (`q` vs `queue`) while popping/front.
- Enqueuing null children without checks.
- Not capturing `levelSize` before processing a level.
- Using DFS when shortest-by-edges answer is required.

## Quick Mental Checklist

- Do I need nearest/shortest-by-edges answer? (Prefer BFS)
- Did I initialize queue with root?
- Do I pop before pushing children?
- For level problems, did I freeze `levelSize` first?
