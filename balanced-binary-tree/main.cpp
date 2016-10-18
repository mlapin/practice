int maxDepth(TreeNode *root, int depth) {
    if (!root) return depth;
    int lh = maxDepth(root->left, depth + 1);
    int rh = (lh >= 0) ? maxDepth(root->right, depth + 1) : -1;
    return (lh >= 0 && rh >= 0 && abs(lh - rh) <= 1) ? max(lh, rh) : -1;
}

bool isBalanced(TreeNode *root) {
    return maxDepth(root, 0) >= 0;
}
