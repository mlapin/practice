vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> r;
    if (!root) return r;
    vector<int> t;
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty()) {
        TreeNode *x = q.front();
        q.pop();
        if (!x) {
            r.push_back(std::move(t));
            if (!q.empty()) q.push(nullptr);
            t.clear();
            continue;
        }
        t.push_back(x->val);
        if (x->left) q.push(x->left);
        if (x->right) q.push(x->right);
    }
    return r;
}
