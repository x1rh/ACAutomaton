class Solution {
public:
    void dfs(vector<int>& ans, TreeNode* root){
        if(root){
            if(root->left) dfs(ans, root->left);
            if(root->right) dfs(ans, root->right);
            ans.emplace_back(root->val);
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(ans, root);
        return ans;
    }
};