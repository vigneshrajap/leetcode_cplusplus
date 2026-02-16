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


    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // 1. If one node is missing, return the other
        if (!root1) return root2;
        if (!root2) return root1;
        
        TreeNode* mergedNode = new TreeNode(root1->val+root2->val);
        
        mergedNode->left = mergeTrees(root1->left, root2->left);

        mergedNode->right = mergeTrees(root1->right, root2->right);
        
        return mergedNode;

    }
};