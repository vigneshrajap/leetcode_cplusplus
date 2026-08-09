# Balanced Binary Tree

Determine whether a binary tree is height-balanced.

A binary tree is balanced if the depth of the two subtrees of every node never differs by more than one.

## Approach

The solution uses a post-order DFS helper that returns the height of a subtree or `-1` if the subtree is unbalanced.

### Idea

1. Recursively compute the height of the left subtree.
2. If the left subtree is unbalanced, propagate `-1` upward.
3. Recursively compute the height of the right subtree.
4. If the right subtree is unbalanced, propagate `-1` upward.
5. If the left and right subtree heights differ by more than 1, return `-1`.
6. Otherwise, return the height of the current subtree.

If the helper returns `-1` for the root, the tree is unbalanced.

See [sample.cpp](sample.cpp).