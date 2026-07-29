# DFS on Tree Template

## Overview

Depth First Search (DFS) explores one branch as deep as possible before backtracking.
On trees, recursive DFS is the same pattern as pre-order traversal:

1. Handle current node.
2. Recurse into children.
3. Return and combine child results.

This style is useful for both:
- visiting/modifying nodes
- computing and returning values from subtrees

## When to Use DFS

- Search for a value in a tree
- Compute subtree properties (height, sum, balance, diameter helper values)
- Build root-to-leaf paths
- Solve combinatorial state-space problems (backtracking)
- Traverse graphs (with a visited set to avoid cycles)

## Core Tree Search Template (Return Matching Node)

```cpp
template <typename T>
struct Node {
    T val;
    Node* left;
    Node* right;
};

template <typename T>
Node<T>* dfs(Node<T>* root, const T& target) {
    if (root == nullptr) return nullptr;       // base case: empty subtree
    if (root->val == target) return root;      // base case: found target

    // Search left subtree first.
    Node<T>* left = dfs(root->left, target);
    if (left != nullptr) return left;

    // Left had no answer; return right result (node or nullptr).
    return dfs(root->right, target);
}
```

Equivalent short form:

```cpp
Node<T>* left = dfs(root->left, target);
return left != nullptr ? left : dfs(root->right, target);
```

This is equivalent to the main template and avoids duplicate DFS calls.

## Generic DFS Shape (Divide and Conquer)

```text
function dfs(node):
    if node is null:
        return base_value

    left_result = dfs(node.left)
    right_result = dfs(node.right)

    return combine(node, left_result, right_result)
```

Think of each recursive call as solving the same problem on a smaller subtree, then combining answers.

## Complexity

For a tree with n nodes:

- Time: O(n), each node is processed at most once.
- Space: O(h), where h is tree height due to recursion stack.
- Height cases: h = O(log n) for balanced trees, O(n) for skewed trees.

## Common Mistakes

- Missing the null base case (causes crashes).
- Forgetting to return child results upward.
- Recomputing recursive calls unnecessarily.
- Using DFS on graphs without visited tracking (infinite loops with cycles).

## Quick Mental Checklist

- What is the base case?
- What should each DFS call return?
- How do left and right subtree results combine?
- Do we need early return when answer is found?
- Is recursion depth safe for worst-case input?
