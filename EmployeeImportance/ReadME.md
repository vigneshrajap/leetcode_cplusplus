# Employee Importance

## Intuition

We need the sum of importance for the given employee and all of their subordinates. Since the structure is a hierarchy, a queue-based BFS traversal is a clean way to visit every reachable employee.

## Approach

1. Build a map from `id` to `Employee*`.
2. Start BFS from the target employee.
3. Pop each employee from the queue, add its `importance`, and enqueue its `subordinates`.
4. Continue until the queue is empty.

## BFS vs DFS

Both are fine here. They are logically equivalent because both traverse all reachable nodes in `O(N)` time. BFS is often more natural for level-by-level traversal, while DFS can use less memory on very deep hierarchies.

## Why no visited set?

No visited set is needed because the problem structure is a tree: every employee has exactly one boss, so there are no cycles and no shared branches that can revisit the same `id`.

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## Code

See [sample.cpp](sample.cpp).
