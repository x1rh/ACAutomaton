# 题目
[1746. 经过一次操作后的最大子数组和](https://leetcode.cn/problems/maximum-subarray-sum-after-one-operation/)

# 题意
求最大连续子数组的和，其中必须使用一次nums[i]*nums[i]

# 思路
定义
- dp[i][0]表示使用过0次nums[i]*nums[i], 且以i为末尾的子数组中的最大和
- dp[i][1]表示使用过1次nums[i]*nums[i], 且以i为末尾的子数组中的最大和
转移方程
- dp[i][0] = (dp[i-1][0] + nums[i], nums[i])
- dp[i][1] = max(dp[i-1][1] + nums[i], dp[i-1][0] + nums[i] * nums[i], nums[i] * nums[i])

```cpp
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size(), ans;
        vector<vector<int>> f(n, vector<int>(2, 0));
        f[0][0] = nums[0];
        ans = f[0][1] = nums[0] * nums[0];
        for(int i=1; i<n; i++) {
            f[i][0] = max(f[i-1][0] + nums[i], nums[i]);
            f[i][1] = max(max(f[i-1][1] + nums[i], f[i-1][0] + nums[i] * nums[i]), nums[i] * nums[i]);
            ans = max(ans, max(f[i][0], f[i][1]));
        }
        return ans;
    }
};
```