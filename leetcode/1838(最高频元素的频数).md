# 思路
1. 排序
2. 可以快速判断一个连续区间是否能经过小于k次操作后变为一样的值
3. 最多k次，可以不使用k次（没注意到这点就会很坑）
4. 又到了讨论滑动窗口为什么是对的时间：
    - 固定区间右端点找一个满足条件的区间左端点，这逻辑上是正确的，无情况遗漏
    - 关键在于左区间需要快速找到
    - 考虑利用前一个区间的信息，将其转移到当前区间，如从[l, r]到[l, r+1]， 这可能导致超过k，所以需要适当的左移l
    - 考虑一个问题，为什么左区间端点值能正确维护？只有两种情况，要么上一个区间全部被包含在下一个区间，要么部分被包含在下一个区间。那会不会出现l左移的情况？答：不会，出现左指针左移那就不属于滑动窗口


## 一般思路：
1. 构造前缀和，方便快速计算
2. 维护l和r
3. 维护答案


## 二分的思想


## 官方题解：
- 用一个total变量来记录区间内花费的操作数
- 每次右移右指针时操作nums[r]-nums[r-1]
- 每次移动左指针时操作nums[r]-nums[l]
非常巧妙


# 代码
```cpp
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        int l=0;
        long long intervalKSum = 0;
        for(int r=1; r<nums.size(); ++r){
            intervalKSum += (long long) (nums[r]-nums[r-1]) * (r-l);
            while(intervalKSum > k){
                intervalKSum -= (nums[r] - nums[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
```
