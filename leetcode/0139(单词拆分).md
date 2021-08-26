# 题目
`https://leetcode-cn.com/problems/word-break/`


# 思路
记dp[i]表示s[0...i-1]可被拆分（值为true）

初始化时，dp[0]=true, 即空串可被dict中表示
则dp[i] = dp[j] && check s[j...i-1] in dict


```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto st = unordered_set<string>();
        for(auto &x : wordDict){
            st.insert(x);
        }
        
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i=1; i<=s.size(); ++i){
            for(int j=0; j<i; ++j){
                if(dp[j] && (st.find(s.substr(j, i-j))!=st.end())){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
```


