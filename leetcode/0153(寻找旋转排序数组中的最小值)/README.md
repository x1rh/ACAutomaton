# 题目
`https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/`


# 思路
解法1 遍历 O(n)
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int mx = 0x3f3f3f3f;
        for(auto &x : nums){
            if(x < mx){
                mx = x;
            }
        }
        return mx;
    }
};
```


解法2 二分，时间复杂度O(logn)

旋转后的数组分为A和B两部分（从左往右），A和B都是左低右高的“坡”（不管怎么旋转）  

只有有序时，最小值在最大值的左侧，否则一直在右侧  

若`nums[l]<=nums[mid] && nums[mid]>=nums[r]` 则mid在A部分，下一步l=mid+1
若`nums[l]>=nums[mid] && nums[mid]<=nums[r]` 则mid在B部分，下一步r=mid

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;

        while(l<r){
            int mid = (l+r) / 2;
            if(nums[mid] >= nums[r]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return nums[r];
    }
};
```
