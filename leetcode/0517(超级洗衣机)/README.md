# 题目
`https://leetcode-cn.com/problems/super-washing-machines/`


# 思路
- 限制了只能左右转移。
- 至少需要转移：`sum(  abs(machines[i] - avg) )` i从0到n-1
- 维护一个ta值，累计之前的`剩余`或`缺少`


参考： `https://leetcode-cn.com/problems/super-washing-machines/solution/acmjin-pai-ti-jie-tan-xin-bian-cheng-xio-mp7n/`


```cpp
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        
        int sm = accumulate(machines.begin(), machines.end(), 0);
        if(sm % machines.size() != 0) return -1;
        int avg = sm / machines.size();
        int ans = 0, ta = 0;
        for(auto &x : machines){
            x -= avg;
            ta += x;
            ans = max(ans, max(abs(ta), x));
        }

        return ans;
    }
};
```

- 注意max(ans, abs(ta), x)的含义，特别需要理解一点，x不取绝对值的原因是，x可以被后面的洗衣机转移而`解决`。
