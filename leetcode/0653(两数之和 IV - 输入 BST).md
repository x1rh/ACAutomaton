# 题目
`https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/`

# 思路
中序遍历获取BST的升序排列，然后O(nlogn)查找是否存在两个元素相加为k


```cpp
class Solution {
public:
    void dfs(TreeNode* rt, vector<int>& ans){
        if(rt){
            dfs(rt->left, ans);
            ans.push_back(rt->val);
            dfs(rt->right, ans);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        dfs(root, ans);
        for(int i=0; i<ans.size()-1; ++i){
            auto it = lower_bound(ans.begin()+i+1, ans.end(), k-ans[i]);
            if(it!=ans.end() && *it==k-ans[i]){
                return true;
            }
        }
        return false;
    }
};
```