# 题目
[1791-找出星型图的中心节点](https://leetcode-cn.com/problems/find-center-of-star-graph/)

# 思路
求度即可

Go
```go
func findCenter(edges [][]int) int {
    mp := make(map[int]int)

    for _, x := range edges {
        mp[x[0]] += 1
        mp[x[1]] += 1
    }

    max := 0
    ans := -1

    for k, v := range mp {
        if v > max {
            max = v
            ans = k
        }
    }
    
    return ans 
}
```

cpp
```cpp
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        map<int, int> deg;
        for(auto &x : edges){
            ++deg[x[0]];
            ++deg[x[1]];
        }
        int _max = INT_MIN;
        int ans = -1;
        for(auto &[k, v] : deg) {
            if(v > _max){
                _max = v;
                ans = k;
            }
        }
        return ans;
    }
};
```