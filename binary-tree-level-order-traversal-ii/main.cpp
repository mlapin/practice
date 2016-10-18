vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> r;
    if (!root) return r;
    vector<TreeNode*> q;
    q.push_back(nullptr);
    q.push_back(root);
    int b = 1;
    while (b < q.size()) {
        int n = q.size();
        q.push_back(nullptr);
        for (int i = b; i < n; ++i) {
            if (q[i]->right) q.push_back(q[i]->right);
            if (q[i]->left) q.push_back(q[i]->left);
        }
        b = n+1;
    }
    vector<int> t;
    q.pop_back();
    while (!q.empty()) {
        TreeNode *x = q.back();
        q.pop_back();
        if (x) {
            t.push_back(x->val);
        } else {
            r.push_back(std::move(t));
            t.clear();
        }
    }
    return r;
}
