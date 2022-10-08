# 题目
`https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/`

# 思路
令dp[i][d] 表示以nums[i]为最后一项，公差为d的等差数列的个数，那么  
1. 当nums[i]=nums[j]==d时，dp[i][d] += dp[j][d] + 1
2. 当nums[i]=nums[j]==d时，dp[i][d] += 1

所以我们枚举i和j即可。

此外需要考虑长度至少为3：
我们利用dp[i][d]第一次不为0时至少长度为2(此时不计数)，然后利用至少在长度为3时再计数即可。

# 解法1：dp
```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        typedef long long ll;
        vector<map<ll, int>> dp(n, map<ll, int>());
        int ans = 0;
        for(int i=1; i<n; ++i){
            for(int j=0; j<i; ++j){
                ll d = 1L * nums[i] - nums[j];
                int val = dp[j][d];
                dp[i][d] += val + 1;
                ans += val;
            }
        }
        return ans;
    }
};
```
我用map的时间复杂度多乘一个O(log(M)), 总时间复杂度为`O(n*n*log(n*n))` 
用哈希表可以将查找的时间复杂度O(log(n*n))降为O(1)

# 细节
int转long long出问题