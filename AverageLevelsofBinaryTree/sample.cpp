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

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> trees;

        if (root==NULL) return result;

        trees.push(root);
        
        while(!trees.empty()){
            int tree_size = trees.size();
            double levelsum = 0;

            for(int i=0; i<tree_size;i++){
                TreeNode* CurrentNode = trees.front();
                trees.pop();

                if(CurrentNode->left!=nullptr) trees.push(CurrentNode->left);
                if(CurrentNode->right!=nullptr) trees.push(CurrentNode->right);

                levelsum += CurrentNode->val;
            }

            result.push_back(levelsum/tree_size);

        }

        return result;        
    }
};