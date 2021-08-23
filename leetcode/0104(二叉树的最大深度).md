# 题目
`https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/`


# 思路
树的最大深度=max(左子树最大深度，右子树最大深度) + 1

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};
```