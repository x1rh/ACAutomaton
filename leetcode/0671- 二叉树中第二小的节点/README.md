# 题目
`https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/`

# 思路
类似于小顶堆，分情况讨论如下：
- 如果有左右子树，那么直接从根节点的左右儿子中选大的即可
- 如果只有左子树（或右子树），左子树里可能又有有左右子树的节点，或者一直都是单边子树

最简单的做法，遍历树，然后将各个值存放在set里，取第二大即可。

```cpp
class Solution {
public:
    void dfs(set<int> &s, TreeNode *root){
        if(root){
            s.insert(root->val);
            dfs(s, root->left);
            dfs(s, root->right);
        }
    }

    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        dfs(s, root);
        if(s.size() >= 2){
            int idx = 1;
            for(auto &it : s){
                if(idx==2){
                    return it;
                }
                ++idx;
            }
        }
        else{
            return -1;
        }
        return -1;
    }
};
```

看了一眼官方题解，感觉自己是傻逼，既然root是最小的节点，那么遍历一次，找到一个比root->val大的最小值即可。