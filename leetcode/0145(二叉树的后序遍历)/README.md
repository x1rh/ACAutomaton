# 题目
`https://leetcode-cn.com/problems/binary-tree-postorder-traversal/`


# 思路
普普通通，后序遍历
```cpp
class Solution {
public:
    void dfs(vector<int>& ans, TreeNode* root){
        if(root){
            if(root->left) dfs(ans, root->left);
            if(root->right) dfs(ans, root->right);
            ans.emplace_back(root->val);
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(ans, root);
        return ans;
    }
};
```
