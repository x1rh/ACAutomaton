# 题目
`https://leetcode-cn.com/problems/super-ugly-number/`

# 题意
如题意所言，找出第n个超级丑数。超级丑数满足其所有的质因数都在给定的primes数组里。

性质：
1. 1是最小的超级丑数
2. 超级丑数x与任意属于primes的质数p的乘积px是超级丑数

# 解法1：递推
维护一个最小堆，将最小的超级丑数1放入堆，利用性质2，每次取出最小的超级丑数与primes中的质数相乘，放入最小堆中。

此外还需要一个map进行去重

```cpp
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        map<long long, bool> vis;
        pq.push(1L);
        vis[1] = true;
        int cnt = 0;
        while(!pq.empty()){
            int tp = pq.top(); pq.pop(); ++cnt;
            if(cnt == n) return tp;            
            for(auto &x : primes){
                long long val = ((long long)x) * tp;
                if(!vis[val]) {
                    pq.push(val);
                    vis[val] = true;
                }
            }
        }
        return -1;
    }
};
```

