class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    void preOrder(vector<int> &v, TreeNode *root){
        if(root){
            v.push_back(root->val);
            if(root->left) preOrder(v, root->left);
            if(root->right) preOrder(v, root->right);
        }
    }
    
    void inOrder(vector<int> &v, TreeNode *root){
        if(root){
            if(root->left) inOrder(v, root->left);
            v.push_back(root->val);
            if(root->right) inOrder(v, root->right);
        }
    }
    
    void postOrder(vector<int> &v, TreeNode *root){
        if(root){
            if(root->left) postOrder(v, root->left);
            if(root->right) postOrder(v, root->right);
            v.push_back(root->val);
        }
    }
    
    vector<vector<int> > threeOrders(TreeNode* root) {
        vector<int> pre, ino, post;
        preOrder(pre, root);
        inOrder(ino, root);
        postOrder(post, root);
        vector<vector<int>> ans{pre, ino, post};
        return ans;
    }
};