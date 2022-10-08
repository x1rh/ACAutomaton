class Solution {
public:
    void dfs(TreeNode* rt, vector<int>& ans){
        if(rt){
            dfs(rt->left, ans);
            ans.push_back(rt->val);
            dfs(rt->right, ans);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        dfs(root, ans);
        for(int i=0; i<ans.size()-1; ++i){
            auto it = lower_bound(ans.begin()+i+1, ans.end(), k-ans[i]);
            if(it!=ans.end() && *it==k-ans[i]){
                return true;
            }
        }
        return false;
    }
};