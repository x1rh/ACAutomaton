# 题目
`https://leetcode-cn.com/problems/find-peak-element/`



# 思路
解法1： 模拟，时间复杂度O(1)  
需要注意一堆细节问题

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        for(int i=1; i<nums.size()-1; ++i){
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1]){
                return i;
            }
        }
        if(nums[0]>nums[1]) return 0;
        if(nums[0]<nums[1]) {
            if(nums.size()==2) return 1;
            if(nums.size()>2 && nums[1]> nums[2]) return 1; 
        }
        if(nums[nums.size()-2] < nums.back()) return nums.size()-1;
        return -1;
    }
};
```


解法2 二分
思路：
- 对于点i，如果`nums[i-1]<nums[i] && nums[i]>nums[i+1]`, 那么这个点是山峰
- i点在下坡
- i点在上坡

对与上坡和下坡，用二分快速结束这个过程。


```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=-1, r=static_cast<int>(nums.size());
        
        auto get = [&](int i){
            if(i==-1 || i==nums.size()){
                return LONG_LONG_MIN;
            }
            else{
                return static_cast<long long>(nums[i]);
            }
        };
        
        while(l <= r){
            int mid = (l+r)/2;
            if((get(mid-1)<get(mid)) && (get(mid)>get(mid+1))){
                return mid;
            }
            else if((get(mid) > get(mid-1)) && (get(mid)<get(mid+1))){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return -1;
    }
};
```
