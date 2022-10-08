# 题目
`https://leetcode-cn.com/problems/longest-increasing-subsequence/`

# 思路

dp[i] 表示长度为i的最长上升子序列的最小末尾值，举例说明：  
有序列[1, 3, 2, 2, 4], 则dp[3]为2，对应的子序列为[1, 2, 2]  

证明当`i<j`时有`dp[i] <= dp[j]`

反证，假设`i<j`时有`dp[i] > dp[j]`

则将`dp[j]`所对应的上升子序列`S`删除末尾`j-i`个得到新的，长度为i的子序列`S'`，记`S'`的最后一个元素val，则
必有`val<= dp[j] < dp[i]`, 而这与我们的dp[i]的定义矛盾（dp[i]存的是长度为i的最小的末尾值）


证单调递增，是为了好维护dp数组，我们按照dp数组的定义维护dp数组，可以利用dp数组的有序性，快速维护。主要是二分维护dp数组比较晦涩，为什么找到位置，就是要更新的位置？答：这是单调递增的隐含条件，规定了某个值，只能插入到dp数组某个下标之前，其中隐含了子序列长度



dp数组的长度，就是最长上升子序列的长度（dp数组不是最长上升子序列）


怎么维护：  
1. 如果当前遍历到的元素大于dp数组的最后一个元素，满足上升性质则直接push_back
2. 否则使用二分维护dp数组

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i=1; i<nums.size(); ++i)
            if(nums[i] > dp.back()){
                dp.push_back(nums[i]);
            }
            else{
                auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
                if(it != dp.end()){
                    *it = nums[i];
                }
            }
        return dp.size();
    }
};
```



## 解法2 朴素dp
设`dp[i]`表示以i为结尾的最长上升子序列的长度  
初始化为`dp[i] = 0`     
转移方程为：  
`dp[i] = max(dp[j] + 1, dp[i])`  其中0<=j<i

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 1);
        int ans = 1;
        for(int i=1; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(nums[j] < nums[i] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            ans = max(ans, dp[i]);
            
        }
        return ans;
    }
};
```