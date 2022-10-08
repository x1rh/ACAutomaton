class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans){
        if(root){
            if(root->left) dfs(root->left, ans);
            ans.emplace_back(root->val);
            if(root->right) dfs(root->right, ans);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};