# 题目 
`https://leetcode-cn.com/problems/reordered-power-of-2/`

# 思路
- 数位分解
- 求数位的全排列
- 对每个可能判断是否是2的幂
- 处理前导0


```cpp
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n==0) return false;
        if(n==1) return true;
        vector<int> d;
        while(n){
            d.push_back(n%10);
            n /= 10;
        }
        sort(d.begin(), d.end());
        do {
            if(d[0] == 0) continue;
            long long x = 0;
            for(auto & el : d){
                x = x*10 + el;
            }
            while(x!=1){
                if((x%2)!=0) break;
                x/=2;
            }
            if(x == 1) return true;

        }while(next_permutation(d.begin(), d.end()));
        return false;
    }
};
```