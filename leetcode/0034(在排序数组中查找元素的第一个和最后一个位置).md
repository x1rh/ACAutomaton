# 题目
`https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/`

# 思路
查找元素的左右区间  
二分查找即可  

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        auto it = lower_bound(nums.begin(), nums.end(), target);
        auto jt = upper_bound(nums.begin(), nums.end(), target);
        if(it==nums.end() || *it!=target){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else{
            ans.push_back(it-nums.begin());
            ans.push_back(jt-1-nums.begin());
            return ans;
        }
    }
};
```