# 题目
`https://leetcode-cn.com/problems/number-of-boomerangs/`

# 思路
给n个点，其中3个点可以组成一个回旋镖当一个点到另外两个点的距离相等时  

点互不相同

求有几个这样的3个点。

解法：
枚举回旋镖`V`的凹点，求其到所有其他点的距离，获得每个距离的个数m，然后这个距离可以构成m*(m-1)个回旋镖



```cpp
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
            int n = points.size();
            int ans = 0;
            if(n<=2) return 0;
            for(auto &x : points){
                map<int, int> mp;
                for(auto &y : points){
                    int d = (x[0]-y[0])*(x[0]-y[0]) + (x[1]-y[1])*(x[1]-y[1]);
                    ++mp[d];
                }
                for(auto &[_, cnt] : mp){
                    ans += cnt * (cnt-1);
                }            
            }
            return ans;
        }
};
```