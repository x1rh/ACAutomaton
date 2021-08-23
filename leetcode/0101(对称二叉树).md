# 题目
`https://leetcode-cn.com/problems/symmetric-tree/`


# 思路
求二叉树是否对称，思路是，同时遍历左右子树，检查左子树的左儿子和右子树的右儿子是否相等，检查左子树的右儿子和右子树的左儿子是否相等


```cpp
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
```