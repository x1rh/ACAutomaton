class Solution {
public:

    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;

        function<void(TreeNode*, int)> dfs1 = [&](TreeNode* rt, int target){
            if(rt){
                if(rt->val == target){
                    ++ans;
                }
                dfs1(rt->left, target-rt->val);
                dfs1(rt->right, target-rt->val);
            }
        };

        function<void(TreeNode*)> dfs2 = [&](TreeNode* rt){
            if(rt){
                dfs1(rt, targetSum);
                dfs2(rt->left);
                dfs2(rt->right);
            }
        };

        dfs2(root);
        return ans;
    }
};