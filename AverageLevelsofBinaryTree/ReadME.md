# Average Levels of Binary Tree

Given the root of a binary tree, return the average value of the nodes on each level.

## Approach

This solution performs a breadth-first search (BFS) level by level using a queue.

### Idea

1. Push the root node into the queue.
2. For each level, process all nodes currently in the queue.
3. Sum their values and count how many nodes appear at that level.
4. Compute the average as `levelSum / levelCount`.
5. Append the average to the result and continue until the queue is empty.

## Implementation details

- `queue<TreeNode*> trees` stores nodes for the current level.
- `tree_size` is the number of nodes at that level.
- `levelsum` accumulates the values for the current level.
- Child nodes are enqueued for the next level.

The code returns a vector of average values for all tree levels.

## Complexity

- Time complexity: O(n), where `n` is the number of nodes in the tree.
- Space complexity: O(w), where `w` is the maximum width of the tree (the maximum number of nodes stored in the queue at once).

See [sample.cpp](sample.cpp).