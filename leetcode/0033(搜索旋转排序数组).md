# 题目
`https://leetcode-cn.com/problems/search-in-rotated-sorted-array/`

# 思路
在排序后旋转了一次的数组中，寻找target，返回其下标


解法1，O(n)遍历
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }
};
```

解法2， O(log n)二分
从mid处划分A和B两部分，则A和B中必定`至少`有一个是有序的。

在有序的一部分中，我们可以判断target是否在里面，从而调整l和r的值


```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<=r){
            int mid = (l+r) / 2;
            if(nums[mid] == target) return mid;
            if(nums[l]<=nums[mid]){
                if(nums[l]<=target && target<=nums[mid]){
                    r = mid;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if(nums[mid+1]<=target && target<=nums[r]){
                    l = mid+1;
                }
                else{
                    r = mid;
                }
            }
        }
        return -1;
    }
};
```