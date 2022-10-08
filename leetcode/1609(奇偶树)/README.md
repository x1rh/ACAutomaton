# 题目
https://leetcode-cn.com/problems/even-odd-tree/

# 题意
判断一棵树是否是奇偶树  

奇偶树的定义是：根节点为第0层，要求奇数层每个节点的值为偶数，且从左往右严格递减，偶数层每个节点的值为奇数，且从左往右严格递增。  

# 思路
二叉树层次遍历即可。注意处理最后一个分隔符。

```cpp
class Solution {
public:
    bool is_odd(int x){
        return x & 1; 
    }

    bool is_even(int x){
        return !(x & 1);
    }

    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int level = 0;
        TreeNode* last = nullptr;

        while(!q.empty()){
            TreeNode* fr = q.front(); q.pop();
            if(fr){
                if(is_odd(level)){
                    if(is_odd(fr->val)) return false;
                    if(last && (last->val <= fr->val)) return false;
                }
                else{
                    if(is_even(fr->val)) return false;
                    if(last && (last->val >= fr->val)) return false;
                }
                if(fr->left) q.push(fr->left);
                if(fr->right) q.push(fr->right);
            }
            else{
                if(last) {
                    q.push(nullptr);
                }
                ++level;
            }
            last = fr;
        }
        return true;
    }
};

```
