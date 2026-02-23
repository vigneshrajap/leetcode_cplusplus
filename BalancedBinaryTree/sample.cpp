#include <algorithm>
#include <cmath>

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // If the helper returns -1, it means the tree is unbalanced
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (node == nullptr) return 0;

        // 1. Check left subtree
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // Propagate the "unbalanced" signal

        // 2. Check right subtree
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // Propagate the "unbalanced" signal

        // 3. Check current node's balance factor
        if (std::abs(leftHeight - rightHeight) > 1) {
            return -1; // Current node is unbalanced!
        }

        // 4. Return the actual height if balanced
        return std::max(leftHeight, rightHeight) + 1;
    }
};