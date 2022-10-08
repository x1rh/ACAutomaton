class Solution {
public:
    void dfs(TreeNode* root, int val){
        if(root){
           if(root->val>=val){
               if(root->left){
                   dfs(root->left, val);
               }
               else{
                   TreeNode* p = new TreeNode(val);
                   root->left = p;
                   return;
               }
           }
           else{
               if(root->right){
                   dfs(root->right, val);
               }
               else{
                   TreeNode* p = new TreeNode(val);
                   root->right = p;
                   return ;
               }
           }
        }
    }


    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* retval = new TreeNode(val);
            return retval;
        }
        dfs(root, val);
        return root;
    }
};