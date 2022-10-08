# 题目
`https://leetcode-cn.com/problems/arranging-coins/`


# 思路
循环即可。

```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0;
        for(int i=1; i<=n; ++i){
            n -= i;
            ++ans;
        }
        return ans;
    }
};
```