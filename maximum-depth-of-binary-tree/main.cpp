int maxDepth(TreeNode *root, int depth = 0) {
    if (root == nullptr) return depth;
    return max(maxDepth(root->left, depth + 1),
               maxDepth(root->right, depth + 1));
}
