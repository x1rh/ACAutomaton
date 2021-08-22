# 题目
`https://leetcode-cn.com/problems/minimum-size-subarray-sum/`


# 思路
找出最短的连续子数组，使得它们的和大于target

## 解法1 暴力
```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum >= s) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
```


## 解法2 滑动窗口
先累加一个和数x，使得x>=target, 对应的[i, j), 此时为了求最短，必须移动左指针i（移动右指针j没有意义），移动后继续维护条件x>=target， 重复这个操作即可。

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0, n=nums.size();
        int sm = 0;
        int ans = 0x3f3f3f3f;
        while(i<n && i<=j){
            for(; j<n&&sm<target; ++j) sm += nums[j];
            if(sm<target){
                break;
            }
            else{
                ans = min(ans, j-i);
                sm -= nums[i];
                ++i;
            }
 
        }
        if(ans == 0x3f3f3f3f) return 0;
        else return ans;
    }
};
```