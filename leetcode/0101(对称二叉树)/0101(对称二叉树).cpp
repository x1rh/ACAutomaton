class Solution {
public:
    bool check(TreeNode* L, TreeNode* R){
        if((L&&(!R))  || ((!L)&&R) ) return false;
        if(L==nullptr && R==nullptr) return true;
        if(L&&R){
            if(L->val!=R->val) 
                return false;
            else 
                return check(L->left, R->right) && check(L->right, R->left);
        } 
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        if(check(root->left, root->right)){
            return true;
        }
        else{
            return false;
        }
    }
};