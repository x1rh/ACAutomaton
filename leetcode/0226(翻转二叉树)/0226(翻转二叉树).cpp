class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* r = invertTree(root->left);
        TreeNode* l = invertTree(root->right);
        root->left = l;
        root->right = r;
        return root;
    }
};