class Solution {
private:
    int tot, target;
    bool flag = false;
public:
    void dfs(TreeNode* root){
        if(flag) return;
        if(root){
            tot += root->val;
            if(root->left==nullptr && root->right==nullptr){
                if(tot == target){
                    flag = true;
                    return;
                }
            }
            dfs(root->left);
            dfs(root->right);
            tot -= root->val;
        }
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        tot = 0;
        target = targetSum;
        dfs(root);
        if(flag){
            return true;
        }
        else{
            return false;
        }
    }
};