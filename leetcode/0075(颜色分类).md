# 题目
`https://leetcode-cn.com/problems/sort-colors/`


# 思路
解法一：直接排序
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};
```


解法2：用三个变量记录，然后更新数组即可