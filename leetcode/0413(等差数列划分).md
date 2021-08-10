# 题目
`https://leetcode-cn.com/problems/arithmetic-slices/`

# 思路
题目中的等差数列的定义：
1. 长度大于等于3
2. 连续序列

设dp[i]标识以nums[i]为结尾的等差数列的个数，那么  
- dp[i+1] = dp[i] + 1 if nums[i-2]-nums[i-1] == nums[i-1] - nums[i]
- dp[i+1] = 0 if nums[i-2]-nums[i-1] != nums[i-1] - nums[i]

# 解法1：dp
```
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for(int i=2; i<nums.size(); ++i){
            if(nums[i-2]-nums[i-1] == nums[i-1]-nums[i]){
                dp[i] = dp[i-1] + 1;
            }
            else{
                dp[i] = 0;
            }
        }
        int ans = 0;
        for(int i=0; i<dp.size(); ++i){
            ans += dp[i];
        }
        return ans;
    }
};
```