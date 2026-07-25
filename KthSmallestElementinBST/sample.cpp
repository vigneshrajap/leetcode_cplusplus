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

    void dfs(TreeNode* node, int& count, int& res){
        if(node==nullptr || count == 0){
            return;
        } 
        
        dfs(node->left, count, res);
        
        count--;

        if (count==0){
            res = node->val;
        }

        else dfs(node->right, count, res);   
    }

    int kthSmallest(TreeNode* root, int k) {
        int res;

        dfs(root, k, res);

        return res;
    }
};