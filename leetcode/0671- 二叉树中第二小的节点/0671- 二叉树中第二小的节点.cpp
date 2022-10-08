class Solution {
public:
    void dfs(set<int> &s, TreeNode *root){
        if(root){
            s.insert(root->val);
            dfs(s, root->left);
            dfs(s, root->right);
        }
    }

    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        dfs(s, root);
        if(s.size() >= 2){
            int idx = 1;
            for(auto &it : s){
                if(idx==2){
                    return it;
                }
                ++idx;
            }
        }
        else{
            return -1;
        }
        return -1;
    }
};