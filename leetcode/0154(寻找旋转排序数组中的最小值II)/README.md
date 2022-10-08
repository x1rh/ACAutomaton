# 题目
`https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/`

# 思路

注意第3种情况：
当numbers[mid] == nums[r]的时候，我们将r减1



```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1, mid;
        while(l < r){
            mid = l + (r-l)/2;
            if(nums[mid] < nums[r]){
                r = mid;
            }
            else if(nums[mid] > nums[r]){
                l = mid + 1;
            }
            else --r;
        }
        return nums[l];
    }   
};
```