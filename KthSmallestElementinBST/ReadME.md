# Kth Smallest Element in a BST

Find the k-th smallest value in a binary search tree (BST).
Because a BST is ordered, an inorder traversal yields values in ascending order.

## Example

Input:
- BST: [3,1,4,null,2]
- k = 1

Output:
- 1

Explanation:
Inorder traversal produces [1,2,3,4], so the 1st smallest element is 1.

## 1) Naive Approach

### Intuition
Collect all node values, sort them, and return the value at index `k - 1`.

### Algorithm
- Traverse the tree and append node values to `v`.
- Sort `v` in ascending order.
- Return `v[k - 1]`.

### Complexity
- Time: `O(n log n)`
- Space: `O(n)` for the vector + recursion stack

### Code
```cpp
class Solution {
public:
    void preOrderTraversal(TreeNode* root, vector<int>& v) {
        if (root == nullptr) return;
        v.push_back(root->val);
        preOrderTraversal(root->left, v);
        preOrderTraversal(root->right, v);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        preOrderTraversal(root, v);
        sort(v.begin(), v.end());
        return v[k - 1];
    }
};
```

## 2) Better Approach

### Intuition
A BST's inorder traversal visits nodes from smallest to largest. This eliminates the need to sort.

### Algorithm
- Perform inorder traversal: left → root → right
- Store values in `v`
- Return `v[k - 1]`

### Complexity
- Time: `O(n)`
- Space: `O(n)` for the vector + recursion stack

### Code
```cpp
class Solution {
public:
    void inOrderTraversal(TreeNode* root, vector<int>& v) {
        if (root == nullptr) return;
        inOrderTraversal(root->left, v);
        v.push_back(root->val);
        inOrderTraversal(root->right, v);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inOrderTraversal(root, v);
        return v[k - 1];
    }
};
```

## 3) Optimal Approach

### Intuition
We only need the k-th smallest item, not the full sorted list. Count nodes during inorder traversal and stop when the k-th node is reached.

### Algorithm
- Traverse inorder
- Decrease `count` for each visited node
- When `count == 0`, record the node value

### Complexity
- Time: `O(n)`
- Space: `O(1)` extra + recursion stack

### Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* node, int& count, int& res) {
        if (node == nullptr || count == 0) {
            return;
        }

        dfs(node->left, count, res);
        count--;

        if (count == 0) {
            res = node->val;
            return;
        }

        dfs(node->right, count, res);
    }

    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        dfs(root, k, res);
        return res;
    }
};
```
