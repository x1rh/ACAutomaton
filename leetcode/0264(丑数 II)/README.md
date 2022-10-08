# 题目
`https://leetcode-cn.com/problems/ugly-number-ii/`

# 解法
参考 [0313-超级丑数](./0313(超级丑数).md)

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        typedef long long LL;
        priority_queue<LL, vector<LL>, greater<LL>> pq;
        map<LL, bool> vis;
        pq.push(1L); vis[1L] = true;
        int cnt = 0;
        vector<LL> v{2, 3, 5};
        while(!pq.empty()){
            LL tp = pq.top(); pq.pop(); ++cnt;
            if(cnt == n) return tp;
            for(auto &x : v){
                LL val = x * tp;
                if(!vis[val]){
                    vis[val] = true;
                    pq.push(val);
                }
            }
        }
        return -1;
    }
};
```