# Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth. The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

## Approach (`sample.cpp`)

This implementation uses recursion and handles the asymmetry between left and right children carefully:

- If the tree is empty, return `0`.
- If the node is a leaf (`left == NULL && right == NULL`), return `1`.
- If one child is null, recursively compute the minimum depth of the other child and add `1`.
- If both children exist, return `1 + min(minDepth(left), minDepth(right))`.

This avoids treating a missing subtree as having depth `0`, which would incorrectly shorten the path.

## Complexity

- Time Complexity: O(n)
  - Each node is visited once.
- Space Complexity: O(h)
  - Recursion stack uses space proportional to the tree height `h`.
  - Worst case: O(n) for a skewed tree.
  - Best case: O(log n) for a balanced tree.

## Notes

- There is no `sample1.cpp` implementation in this folder, so this README documents the available recursive solution.
