void visit(TreeNode *x, int sum, vector<int> &q, vector<vector<int>> &r) {
    sum -= x->val;
    q.push_back(x->val);
    if (x->left || x->right) {
        if (x->left) visit(x->left, sum, q, r);
        if (x->right) visit(x->right, sum, q, r);
    } else if (sum == 0) {
        r.push_back(q);
    }
    q.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> r;
    if (root) {
        vector<int> q;
        visit(root, sum, q, r);
    }
    return r;
}
