# 题目
`https://leetcode-cn.com/problems/decode-ways/`



# 思路
设dp[i]表示 以s[i]为结尾的组合数，我们只关注最后一次解码的情况即可。最后一次解码有两种情况，一是只使用了最后一个字符，二是使用了最后两个字符
- 初始化为dp[0] = 1   表示空串有一种组合  
- 转移方程：
  - `dp[i] = dp[i-1] if s[i-1]!='0'`
  - `dp[i] = dp[i-2] if s[i-2]!='0' && (s[i-2]-'0') * 10 + (s[i-1]-'0')`


```cpp
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i=1; i<=s.size(); ++i){
            if(s[i-1] != '0'){
                dp[i] = dp[i-1];
            }
            if(i-2>=0 && s[i-2]!='0' && (s[i-2]-'0')*10+(s[i-1]-'0')<=26 ){
                dp[i] += dp[i-2];
            }
        }
        return dp[s.size()];
    }
};
```

