/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int minDepth(TreeNode* root) {
    // 1. If the tree is empty, depth is 0
    if (root == NULL) return 0;
    
    // 2. If it's a leaf node, depth is 1
    if (root->left == NULL && root->right == NULL) return 1;

    // 3. If left child is NULL, we MUST go right
    if (root->left == NULL) return 1 + minDepth(root->right);

    // 4. If right child is NULL, we MUST go left
    if (root->right == NULL) return 1 + minDepth(root->left);

    // 5. If both exist, take the shorter one
    return 1 + min(minDepth(root->left), minDepth(root->right));

    }
};