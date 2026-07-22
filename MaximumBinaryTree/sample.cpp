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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }

private:
    TreeNode* build(const vector<int>& nums, int start, int end) {
        // Base case: empty range yields nullptr
        if (start >= end) {
            return nullptr;
        }

        // Find max element in current range [start, end)
        auto max_it = max_element(nums.begin() + start, nums.begin() + end);
        int max_idx = distance(nums.begin(), max_it);

        // Construct root node
        TreeNode* root = new TreeNode(*max_it);

        // Recursively construct left and right subtrees
        root->left = build(nums, start, max_idx);       // Range: [start, max_idx)
        root->right = build(nums, max_idx + 1, end);    // Range: [max_idx + 1, end)

        return root;
    }
};