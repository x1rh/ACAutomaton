# 题目
`https://leetcode-cn.com/problems/destination-city/`


# 思路
- 求出度即可。    
- 注意初始化。  



```cpp
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> out;

        for(auto &x : paths){
            string &fr = x[0];
            string &to = x[1];
            out[fr] = 0;
            out[to] = 0;
        }

        for(auto &x : paths){
            string &fr = x[0];
            out[fr] += 1;
        }

        for(auto &[k, v] : out){
            if(v==0){
                return k;
            }
        }
        return "";
    }
};
```
