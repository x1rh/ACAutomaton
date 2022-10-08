class Solution {
public:
    void dfs(TreeNode* root, TreeNode* tar, vector<TreeNode*>& vis){
        if(root){
            vis.push_back(root);
            if(root==tar){
                return;
            }
            else if(tar->val <= root->val){
                dfs(root->left, tar, vis);
            }
            else{
                dfs(root->right, tar, vis);
            }
        }
    }

    int dfs2(TreeNode* root, TreeNode* tar, vector<TreeNode*>& vis, int idx){
        if(root){
            if(idx>=vis.size()) return vis.size()-1;
            if(vis[idx] != root){
                return idx-1;
            }
            if(root == tar){
                return idx;
            }
            else if(tar->val <= root->val){
                return dfs2(root->left, tar, vis, idx+1);
            }
            else{
                return dfs2(root->right, tar, vis, idx+1);
            }
        }
        return -1;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vis;
        dfs(root, p, vis);
        int idx = dfs2(root, q, vis, 0);
        assert(idx>=0);
        return vis[idx];
    }
};