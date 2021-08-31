# 题目
`https://leetcode-cn.com/problems/happy-number/`


# 思路
- 一位数平方后最多变为两位数，而每个数位的平方求和后得到的数，可能比原来的数小，所以不会爆int  
- `非快乐数`存在`循环节点`


```cpp
class Solution {
public:
    bool check(int n, map<int, bool>& vis){
            int t = 0;
            while(n){
                int g = n % 10;
                n/=10;
                t += g*g;
            }
            if(vis[t]){
                return false;
            }
            vis[t] = true;
            if(t!=1){
                return check(t, vis);
            }
            return true;
        }


    bool isHappy(int n) {
        map<int, bool> vis;
        return check(n, vis);
        
    }
};
```