# 题目
`https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/`


# 思路
实现BST的插入  
先找到插入位置的父节点，然后插入即可，需要特判`root=nullptr`的情况


```cpp
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
```
