class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans){
        if(root){
            ans.emplace_back(root->val);
            if(root->left) dfs(root->left, ans);
            if(root->right) dfs(root->right, ans);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};