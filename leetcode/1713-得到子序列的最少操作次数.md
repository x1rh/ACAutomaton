# 题目
`https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence/`


# 思路
题目要在`arr`中添加最少的元素，使得`target`成为`arr`的子序列

`target`为不可变的，无重复元素数组

题解为转换为最长上升子序列来做，如果有重复的元素，就不能这么做了，这题目显然是从答案逆推而来的


```cpp
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        map<int, int> mp;
        for(int i=0; i<target.size(); ++i){
            mp[target[i]] = i+1;
        }

        vector<int> vec;
        for(auto &el : arr){
            int idx = mp[el];
            if(idx){
                vec.push_back(idx);
            }
        }

        vector<int> dp;
        if(vec.empty()){
            return target.size();
        }
        dp.push_back(vec[0]);
        for(int i=1; i<vec.size(); ++i){
            if(vec[i] > dp.back()){
                dp.push_back(vec[i]);
            }
            else{
                auto it = lower_bound(dp.begin(), dp.end(), vec[i]);
                if(it != dp.end()){
                    *it = vec[i];
                }
            }
        }
        return target.size() - dp.size(); 
    }
};
```


# golang 版本
```go
func minOperations(target []int, arr []int) int {
    mp := make(map[int]int)
    m := len(target)
    n := len(arr)
    for i:=0; i<m; i++ {
        mp[target[i]] = i
    }

    d := []int{}
    for i:=0; i<n; i++ {
        v, ok := mp[arr[i]]
        if !ok {
            continue 
        }
        if len(d) == 0 {
            d = append(d, v)
        } else {
            if v > d[len(d)-1] {
                d = append(d, v)
            } else {
                idx := sort.SearchInts(d, v)
                d[idx] = v 
            }
        }
    }
    return m - len(d) 
}
```