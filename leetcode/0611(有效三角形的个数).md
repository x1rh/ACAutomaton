# 题目
`https://leetcode-cn.com/problems/valid-triangle-number/`

# 思路
满足"三角形最短的两边之和大于第三边"条件的一定能组成三角形（充分条件）

遍历思路：
i属于`[0, n-2)`，j属于`[i+1, n-1)`, k属于`[j+1, n)`

这样能保证遍历完整，且不重复，且利用了充分条件。 

找k的时候可以通过二分查找，找到k< i+j的合理的下标.  

时间复杂度为O(`n*n*logn`)，n是1000，不会T。

```cpp
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 3) return 0;
        int ans = 0;
        for(int i=0; i<nums.size()-2; ++i){
            for(int j=i+1; j<nums.size()-1; ++j){
                auto idx = lower_bound(nums.begin()+j+1, nums.end(), nums[i]+nums[j]);
                idx--;
                if(*idx<nums[i]+nums[j]){
                    int tmp = (idx - nums.begin() -j - 1 + 1);
                    if(tmp > 0){
                        ans += tmp;
                    }
                }
            }
        }
        return ans;
    }
};
```



# 官方题解
排序加双指针，时间复杂度为O(n^2)

nums[i] + nums[j] > nums[k] 固定i时，k和j同向增长，所以维护k的时间复杂度近似合并在j中
```cpp
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 3) return 0;
        int ans = 0;
        for(int i=0; i<nums.size()-2; ++i){
            int k = i+2;
            for(int j=i+1; j<nums.size()-1; ++j){
                if(nums[k] < nums[i]+nums[j]){
                    while(k<nums.size() && nums[k] < nums[i]+nums[j]){
                        ++k;
                    }
                    --k;
                    ans += max(0, k-j);   
                }
                
            }
        }
        return ans;
    }
};
``` 

其中，ans+=max(0, k-j)这一步是必须的，因为k可能不满足k>j这一条件。。。