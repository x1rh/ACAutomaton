# 题目
[213. 打家劫舍 II]()

# 题意
选1不能选n，不能选连续的两个，求最大和

# 思路
- 设dp[i]为以i为结尾的最大金钱和，转移方程为`dp[i] = max(dp[i-1], dp[i-2]+nums[i])`
- 从1到n-1，从2到n分别计算dp
- 思考：为什么分开计算是对的？答：（1）起点不同 （2）重叠部分在两种情形下都计算了，没有遗漏状态

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> f(n+2);
        if(n == 1) {
            return nums[0];
        } else if(n == 2) {
            return max(nums[0], nums[1]);
        }

        f[0] = f[1] = 0;
        for(int i=0; i<n-1; i++) {
            f[i+2] = max(f[i+1], f[i] + nums[i]);
            if(f[i+2] > ans) {
                ans = f[i+2];
            }
        }   
        f[0] = f[1] = f[2] = 0;
        for(int i=1; i<n; i++) {
            f[i+2] = max(f[i+1], f[i] + nums[i]);
            if(f[i+2] > ans) {
                ans = f[i+2];
            }
        }
        return ans; 
    }

};
```
