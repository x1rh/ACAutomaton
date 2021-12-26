# 题目
https://leetcode-cn.com/problems/number-of-smooth-descent-periods-of-a-stock/

# 思路
双指针求出每一个平滑的下跌区间，设每个区间的长度为len，则每个区间对答案的贡献是(1+len)*len/2，求和即可。


```cpp
typedef long long ll;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int j;
        ll ans = 0;
        for(int i=0; i<n; ){
            for(j=i+1; j<n&&prices[j-1]-1==prices[j]; ++j);
            
            ll len = j - i;
            ans += (1+len) * len / 2;
            i = j;
        }
        return ans;
    }
};
```