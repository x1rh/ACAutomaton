# 题目
`https://leetcode-cn.com/problems/invert-binary-tree/`

# ps
这个问题是受到 Max Howell 的 原问题 启发的 ：

谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。  

太损了


# 思路
先翻转左右子树，然后更新当前节点的left和right指针即可

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* r = invertTree(root->left);
        TreeNode* l = invertTree(root->right);
        root->left = l;
        root->right = r;
        return root;
    }
};
```