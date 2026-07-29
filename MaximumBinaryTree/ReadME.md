# Maximum Binary Tree

Given an integer array `nums`, construct a binary tree such that:
- the root is the maximum value in the current range,
- the left subtree is built from the elements to the left of the maximum,
- the right subtree is built from the elements to the right of the maximum.

## Approach

The solution uses a recursive divide-and-conquer strategy:

1. If the range is empty (`start >= end`), return `nullptr`.
2. Find the maximum element in the current range using `max_element`.
3. Create a new `TreeNode` with that maximum value as the root.
4. Recurse on the left half and right half around the maximum index.

This is exactly how the code in `sample.cpp` works:

- `constructMaximumBinaryTree(nums)` calls `build(nums, 0, nums.size())`
- `build(nums, start, end)` works on the range `[start, end)`
- the maximum index splits the array into left and right parts

## Time Complexity

- Worst-case time: `O(n^2)`
- Space complexity: `O(h)` recursion stack, where `h` is the height of the tree

## Key Idea

Each recursive call picks the largest value in the current segment and makes it the root of that subtree, ensuring the final tree follows the problem's required structure.
