# 题目
`https://leetcode-cn.com/problems/jump-game/`


# 思路
在位置i最多向右移动nums[i]步，问是否能走到n

解法1， 暴力dp

设`dp[i]`表示下标i所能到达的最右边的位置，则有转移方程：  
- `dp[i] = max(dp[j])` 其中j属于`[i, nums[i]+i]` 
- 初始化`dp[n-1] = n-1`

算了时间复杂度最多O(n^2)，勉强能过，然后过了

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[n-1] = n-1;
        for(int i=n-2; i>=0; --i){
            if(nums[i]+i+1 >= n) dp[i] = n-1;
            else{
                for(int j=i; j<n && j<=i+nums[i]; ++j){
                    dp[i] = max(dp[j], dp[i]);
                }
            }
        }
        if(dp[0] == n-1) return true;
        else return false;
    } 
};
```

