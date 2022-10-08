# 题目
`https://leetcode-cn.com/problems/count-and-say/`


# 思路
模拟即可，每个数的个数不可能超过10

```cpp
class Solution {
public:
    string countAndSay(int n) {
        vector<string> vec = {"1", "11", "21", "1211", "111221"};
        if(n<=5) return vec[n-1];
        else{
            string ts = "";
            for(int i=5; i<n; ++i){
                int j, k;
                string ts;
                for(j=0; j<vec.back().size();){
                    for(k=j; vec.back()[k]==vec.back()[j]; ++k);
                    ts += (k-j) + '0';
                    ts += vec.back()[j];
                    j = k;
                }
                vec.push_back(ts);
            }
            return vec[n-1];
        }
    }
};
```