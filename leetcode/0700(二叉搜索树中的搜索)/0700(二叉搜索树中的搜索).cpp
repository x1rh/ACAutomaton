class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root){
            if(root->val == val){
                return root;
            }
            else{
                TreeNode* l = searchBST(root->left, val);
                if(l && l->val==val) return l;
                TreeNode* r = searchBST(root->right, val);
                if(r && r->val==val) return r;
                return nullptr;
            }
        }
        return nullptr;
    }
};