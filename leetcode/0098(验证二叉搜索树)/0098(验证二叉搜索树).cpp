class Solution {
private:
    bool flag;
    vector<TreeNode*> v;
public:
    bool isValidBST(TreeNode* root) {
        flag = true;
        dfs(root);
        if(flag && isValid(root)){
            return true;
        }
        return false;
    }

    void dfs(TreeNode* root){
        if(flag && root){
            dfs(root->left);
            if(!v.empty()){
                if(v.back()->val>=root->val) flag = false;
            }
            v.emplace_back(root);
            dfs(root->right);
        }
    }


    bool isValid(TreeNode* root) {
        if(root){
            bool l=false, r=false;
            if(root->left){
                if(root->left->val < root->val){
                    l = isValid(root->left);
                }
                else{
                    l = false;
                }   
            }
            else{
                l = true;
            }
            if(root->right){
                if(root->right->val > root->val){
                    r = isValid(root->right);
                }
                else{
                    r = false;
                }
            }
            else{
                r = true;
            }
            return l && r;
        }
        return true;
    }
};