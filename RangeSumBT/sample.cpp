struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == nullptr) return 0;

    // Case 1: Node value is smaller than 'low'
    // Skip this node and the entire left subtree
    if (root->val < low) {
        return rangeSumBST(root->right, low, high);
    }

    // Case 2: Node value is larger than 'high'
    // Skip this node and the entire right subtree
    if (root->val > high) {
        return rangeSumBST(root->left, low, high);
    }

    // Case 3: Node is within range [low, high]
    // Add current value and check both children
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}