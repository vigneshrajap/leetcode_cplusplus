bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    
    // We put two nodes in the queue to compare them against each other
    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);
    
    while (!q.empty()) {
        TreeNode* t1 = q.front(); q.pop();
        TreeNode* t2 = q.front(); q.pop();
        
        // If both are null, this specific "pair" is symmetric
        if (!t1 && !t2) continue;
        
        // If one is null or values mismatch, it's not symmetric
        if (!t1 || !t2 || t1->val != t2->val) return false;
        
        // Push children in "mirror" order:
        q.push(t1->left);  q.push(t2->right); // Outer pair
        q.push(t1->right); q.push(t2->left);  // Inner pair
    }
    
    return true;
}