# 题目
`https://leetcode-cn.com/submissions/detail/202670812/`

# 题意&&思路

找到最短的连续子数组SubArray，使得，当SubArray有序后，整个数组有序

sort一次，两个数组对比即可，时间复杂度为O(nlogn), 空间复杂度为O(n)
```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sort_nums = nums;
        sort(nums.begin(), nums.end());

        int ii=-1, jj=-1;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] != sort_nums[i]){
                ii = i;
                break;
            }
        }
        for(int i=nums.size()-1; i>=0; --i){
            if(nums[i] != sort_nums[i]){
                jj = i;
                break;
            }
        }
        if(ii == jj) return 0;
        return jj - ii + 1;

    }
};
```

# 其他解
时间复杂度为O(n)，空间复杂度为O(1)的解法：
找到一个最左的和一个最右的，解法十分巧妙（主要在于左右指针的更新）

```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxn = INT_MIN;
        int minn = INT_MAX;
        int left=-1, right=-1;
        for(int i=0; i<nums.size(); ++i){
            if(maxn > nums[i]){
                right = i;
            }
            else{
                maxn = nums[i];
            }

            int j = nums.size()-i-1;
            if(minn < nums[j]){
                left = j;
            }
            else{
                minn = nums[j];
            }

        }
        return left==right ? 0 : right-left+1;
    }
};
```