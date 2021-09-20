# 题目
`https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/`


# 思路
用了两个dp求这题

设dp[i]表示以i为结尾的最长上升子序列的长度:
- 初始化为dp[0] = 1;
- 转移方程 `dp[i] = (d[j]+1, dp[i]) if (0<=j<i && nums[j]<nums[i]) `


设rc[i][j]表示长度为i且以nums[j]为结尾的的**最长**上升子序列的个数:
- 注意这个设 包含了3个条件，长度i，结尾j，最长上升子序列
- `1<=i<=n, 0<=j<n`
- 初始化为`rc[1][i] = 1   0<=i<n`
- 转移为`rc[i][j] += rc[i-1][k]  if(nums[k]<nums[j])  0<=k<j<n`


```cpp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<vector<int>> rc(n+1, vector<int>(n, 0));
        int ans = 1;
        for(int i=0; i<n; ++i){
            rc[1][i] = 1;
        }
        for(int i=1; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(nums[j]<nums[i]){
                    if(dp[j]+1>dp[i]){
                        dp[i] = dp[j] + 1;
                        rc[dp[i]][i] += rc[dp[i]-1][j];
                    }
                    else if(dp[j]+1 == dp[i]){
                        rc[dp[i]][i] += rc[dp[i]-1][j];
                    }
                    
                }
            }
            ans = max(ans, dp[i]);
        }
        
        int retval = 0;
        for(int i=0; i<n; ++i){
           retval += rc[ans][i];
        }
        return retval;
    }
};
```


# 解法2： dp
题目要求我们求长度为max_length的最长递增子序列的个数

求最长递增子序列是容易的，同时以nums[i]为结尾的长度为x的子序列的个数c也是能维护的。

记dp[i] = [len, cnt]表示以nums[i]为结尾的最长递增子序列的长度为len, 个数为cnt.

那么转移方程也很简单：
```cpp
if(nums[i]>nums[j]){
    if(dp[i].first < dp[j].first+1){
        dp[i].first = dp[j].first+1;
        dp[i].second = dp[j].second;
        maxl = max(maxl, dp[i].first);
    }
    else if(dp[i].first == dp[j].first+1){
        dp[i].second += dp[j].second;
    }
}                
```



```cpp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {1, 1});
        int maxl = 1;
        for(int i=0; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(nums[i]>nums[j]){
                    if(dp[i].first < dp[j].first+1){
                        dp[i].first = dp[j].first+1;
                        dp[i].second = dp[j].second;
                        maxl = max(maxl, dp[i].first);
                    }
                    else if(dp[i].first == dp[j].first+1){
                        dp[i].second += dp[j].second;
                    }
                }                
            }
        }
        int ans = 0;
        for(auto &[l, c] : dp){
            if(l == maxl){
                ans += c;
            }
        }
        return ans;
    }
};
```