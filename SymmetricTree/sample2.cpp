class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // An empty tree is symmetric
        if (!root) return true;
        
        // Compare the left and right subtrees
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // If both nodes are null, they are symmetric
        if (t1 == nullptr && t2 == nullptr) return true;
        
        // If only one is null, or values don't match, they aren't symmetric
        if (t1 == nullptr || t2 == nullptr) return false;
        if (t1->val != t2->val) return false;

        // Recursively check:
        // 1. Left of t1 with Right of t2 (Outer pair)
        // 2. Right of t1 with Left of t2 (Inner pair)
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};