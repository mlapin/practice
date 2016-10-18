vector<int> postorderTraversal(TreeNode* root) {
    vector<int> r;
    if (!root) return r;
    stack<pair<bool, TreeNode*>> q;
    q.emplace(false, root);
    while (!q.empty()) {
        auto &p = q.top();
        TreeNode *x = p.second;
        if (p.first) {
            q.pop();
            r.push_back(x->val);
        } else {
            p.first = true;
            if (x->right) q.emplace(false, x->right);
            if (x->left) q.emplace(false, x->left);
        }
    }
    return r;
}
