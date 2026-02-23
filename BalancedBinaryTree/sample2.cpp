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
    bool isBalanced(TreeNode* root) {

        TreeNode* currNode = root;

        int n = 0;
        while(currNode!=nullptr){
            currNode = currNode->left;
            n++;
        }

        currNode = root;

        int m = 0;
        while(currNode!=nullptr){
            currNode = currNode->right;
            m++;
        }

        if (abs(n-m)>1) return false;
        return true;
    }
};