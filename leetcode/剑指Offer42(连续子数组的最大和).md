# 题目
`https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/`


# 思路
dp[i]表示以下标i为结尾的连续子数组的最大和。

在dp[i]>0的时候，我们总希望它能够继续和下一个nums[j]进行结合
如果dp[i]<0, 那么dp[i+1] = nums[i+1]


```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        int ans = nums[0];
        dp[0] = nums[0];
        for(int i=1; i<n; ++i){
            if(dp[i-1]<0) dp[i] = nums[i];
            else dp[i] = dp[i-1] + nums[i];
            if(dp[i] > ans) ans = dp[i];
        }
        return ans;
    }
};
```