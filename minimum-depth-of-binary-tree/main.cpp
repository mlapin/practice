int minDepth(TreeNode* root, int depth = 0) {
    if (root == nullptr) return depth;
    if (root->left && root->right)
        return min(minDepth(root->left, depth + 1),
                   minDepth(root->right, depth + 1));
    return root->left ? minDepth(root->left, depth + 1)
                      : minDepth(root->right, depth + 1);
}
