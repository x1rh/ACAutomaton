# 题目
`https://leetcode-cn.com/submissions/detail/226608638/`

# 思路
找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

用map记录即可。



```cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> ans;
        if(n<10) return ans;
        string ts = s.substr(0, 10);
        map<string, int> mp;
        mp[ts] = 1;
        for(int i=10; i<n; ++i){
            ts = ts.substr(1, 9) + s[i];
            auto it = mp.find(ts);
            if(it != mp.end()){
                if(it->second == 1){
                    ans.push_back(it->first);
                    it->second += 1;
                }
            }
            else{
                mp[ts] = 1;
            }
        }
        return ans;
    }
};
```