# 题目
`https://leetcode-cn.com/problems/nim-game/`

# 思路
博弈论

两人从一堆石子中轮流取石子，最少取1个，最多取m个，第一个人先取，求第一个人是否能最后取完石子。


```cpp
class Solution {
public:
    bool canWinNim(int n) {
        if(n%4==0) return false;
        else return true;
    }
};
```