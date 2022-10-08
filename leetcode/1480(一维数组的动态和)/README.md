# 题目
`https://leetcode-cn.com/problems/running-sum-of-1d-array/`

# 思路
求前缀和


```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) { 
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for(int i=1; i<n; ++i){
            dp[i] = dp[i-1] + nums[i];
        }
        return dp;
    }
};
```