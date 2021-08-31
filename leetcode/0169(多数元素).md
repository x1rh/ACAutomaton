# 题目
`https://leetcode-cn.com/problems/majority-element/`


# 思路

`Boyer-Moore`投票算法

时间复杂度O(n), 空间复杂度O(1)

通俗的介绍一下算法：
有超过一半的人是A国的，其他为小国B、C、D的，那么A和BCD血拼，一换一后，最后A国还是剩下有人。


```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can = -1;
        int cnt = 0;
        for(auto &x : nums){
            if(cnt==0){
                ++cnt;
                can = x;
            }
            else if(x == can){
                ++cnt;
            }
            else{
                --cnt;
            }
        }
        return can;
    }
};
```