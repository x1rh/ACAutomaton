# 题目
`https://leetcode-cn.com/problems/escape-the-ghosts/`

# 思路
- 停下来和不停下来没区别
- 以最短代价到达target之前，若其他ghost都不能到达target则为true
- 不需要考虑绕路


```cpp
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> you{0, 0};
        
        auto dist = [](vector<int>& st, vector<int>& ed){
            return abs(st[0] - ed[0]) + abs(st[1] - ed[1]);
        };

        int d = dist(you, target);
        for(auto &x : ghosts){
            if(d>= dist(x, target)){
                return false;
            }
        }
        return true;
    }
};
```