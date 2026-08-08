# Range Sum of BST

Given the root of a binary search tree and two integers `low` and `high`, return the sum of values of all nodes with a value in the inclusive range `[low, high]`.

## Approach (sample.cpp)

The implementation uses recursion with direct checks and early returns:

- If the current node is `nullptr`, return 0.
- If `node->val < low`, skip the left subtree entirely and recurse into the right subtree.
- If `node->val > high`, skip the right subtree entirely and recurse into the left subtree.
- Otherwise, the node is within range: add `node->val` and recurse into both children.

This leverages BST ordering to prune subtrees that cannot contain values in the range.

## Approach (sample2.cpp)

This implementation extracts the logic into a helper `dfs` that:

- Adds the current node's value if it lies in `[low, high]`.
- Recurse left only if `node->val > low` (left subtree may contain values in range).
- Recurse right only if `node->val < high` (right subtree may contain values in range).

Functionally this is equivalent to `sample.cpp` but the helper structure separates concerns and can be easier to read.

## Complexity

- Time Complexity: O(n) in the worst case (where `n` is the number of nodes). In practice, the BST pruning often reduces the number of visited nodes, so the average/typical cost is lower when large subtrees can be skipped.
- Space Complexity: O(h) due to recursion stack, where `h` is the tree height. In the worst case (skewed tree) `h = O(n)`, and in a balanced tree `h = O(log n)`.

## Notes

- Both implementations are correct and have the same asymptotic bounds; prefer the helper-based `sample2.cpp` for readability.
- An iterative approach using an explicit stack or BFS queue can be used to avoid recursion and control stack usage.
