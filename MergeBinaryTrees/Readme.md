# Merge Two Binary Trees

Given two binary trees, merge them into a single binary tree. If two nodes overlap, sum their values as the new node's value; otherwise, use the existing non-null node.

## Approach (`sample.cpp`) — Recursive merge (creates new nodes)

- If one of the nodes is null, return the other node.
- Otherwise, create a new node with value `root1->val + root2->val`.
- Recursively merge left children and right children.
- Return the newly created merged node.

This approach constructs a new tree and preserves the input trees.

### Complexity (`sample.cpp`)

- Time Complexity: O(m), where `m` is the number of nodes present in either tree (i.e., nodes visited).
- Space Complexity: O(h), where `h` is the height of the merged tree due to recursion stack (worst-case O(m) for a skewed tree, O(log m) for balanced trees).

## Alternative — Iterative in-place merge (modify one tree)

An alternative is to merge `root2` into `root1` in-place using a stack or queue:

- Push pairs of nodes `(root1, root2)` onto a stack.
- While stack not empty:
  - Pop a pair `(n1, n2)`.
  - If `n2` is null continue.
  - If `n1` is null, attach `n2` at the correct parent position.
  - Otherwise, add `n2->val` to `n1->val`.
  - Push children pairs accordingly (left-left, right-right).

This modifies `root1` (no new nodes for overlapping parts), and can be more memory-efficient if modifying inputs is acceptable.

### Complexity (iterative in-place)

- Time Complexity: O(m), same as recursive.
- Space Complexity: O(h) for the explicit stack/queue (worst-case O(m)).

## Notes

- Use the recursive version (`sample.cpp`) when you want a clean, functional-style merge that preserves inputs.
- Use the iterative/in-place version when you need to avoid allocating many new nodes and can mutate one of the input trees.

File updated: `MergeBinaryTrees/Readme.md`