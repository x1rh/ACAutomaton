# 题目
`https://leetcode-cn.com/problems/path-sum-iii/`


# 思路
以当前节点为起点，向下遍历，求是否能构成和为targetSum

一个dfs用来遍历树，另一个dfs用来求和

时间复杂度O(n^2)

```cpp
class Solution {
public:

    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;

        function<void(TreeNode*, int)> dfs1 = [&](TreeNode* rt, int target){
            if(rt){
                if(rt->val == target){
                    ++ans;
                }
                dfs1(rt->left, target-rt->val);
                dfs1(rt->right, target-rt->val);
            }
        };

        function<void(TreeNode*)> dfs2 = [&](TreeNode* rt){
            if(rt){
                dfs1(rt, targetSum);
                dfs2(rt->left);
                dfs2(rt->right);
            }
        };

        dfs2(root);
        return ans;
    }
};
```