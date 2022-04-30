# 题目
[1712. 将数组分成三个子数组的方案数](https://leetcode-cn.com/problems/ways-to-split-array-into-three-subarrays/)

# 题意
将非负数组分为三个连续的部分，使得三部分的和非递减，求满足条件的方案数。


# 思路
设前缀和数组`pre`, 那么：
- `pre[l] <= pre[r] -pre[l] <= pre[n] - pre[r]`
- 我们需要一个桥梁，显然是固定r，所以等价变形为： `2*pre[r]-pre[n] <= pre[l] <= pre[r]/2`
- 考虑到除2不准确，可变形为左边右开区间：`2*pre[r]-pre[n] <= pre[l] < pre[r]/2+1`
- 具体做法，枚举在区间`[2, n)`上枚举r，pre数组是单调的，二分确定`pre[l]`的左右区间。


```cpp
typedef long long ll;
const int mod = 1e9+7;

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pre(n+1);
        for(int i=1; i<=n; i++) {
            pre[i] = nums[i-1] + pre[i-1];
        }

        int ans = 0;
        for(int i=2; i<n; i++) {
            ll key1 = 2*pre[i]-pre[n];
            ll key2 = pre[i]/2 + 1;
            auto it1 = lower_bound(pre.begin()+1, pre.begin()+i, key1);
            auto it2 = lower_bound(it1, pre.begin()+i, key2);
            ans = (ans + (it2-it1)%mod)%mod;
        }
        return ans;
    }
};
```