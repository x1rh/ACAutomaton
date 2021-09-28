# 题目
`https://leetcode-cn.com/problems/decode-ways-ii/`


# 思路
记dp[i]表示前i个字符所能构成的所有解码数，我们每次只考虑当前位置或与前一个位置的组合所能构成的组合。那么dp[i] 只和dp[i-1]和dp[i-2]有关，直接递推即可求得。

由于存在特殊字符`*`, 需要分情况讨论`1*, 2*, **, *x`

```cpp
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        const int mod = 1000000000 + 7;
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        for(int i=1; i<=n; ++i){
            if(s[i-1] == '*'){
                dp[i] = (dp[i-1] * 9) % mod;
                if(i-2 >= 0){
                    if(s[i-2] == '1') dp[i] = (dp[i] + (dp[i-2] * 9) % mod) % mod;
                    else if(s[i-2] == '2') dp[i] = (dp[i] + (dp[i-2] * 6) % mod) % mod;
                    else if(s[i-2] == '*') dp[i] = (dp[i] + (dp[i-2] * 15) % mod) % mod;
                    else continue;
                }                    
            }
            else if(s[i-1] == '0'){
                if(i-2 >= 0){
                    if(s[i-2] == '*'){
                        dp[i] = (dp[i-2] * 2) % mod;
                    }
                    else if(s[i-2]=='1' || s[i-2]=='2'){
                        int x = (s[i-2] - '0') * 10 + (s[i-1] - '0');
                        if(1<=x && x<=26){
                            dp[i] = dp[i-2];
                        }
                    }
                }
            }
            else{
                dp[i] = dp[i-1];
                if(i-2 >= 0){
                    if(s[i-2] == '*'){
                        int mul = 0;
                        if((s[i-1]-'0') > 6 ) mul = 1;
                        else mul = 2; 

                        dp[i] = (dp[i] + (dp[i-2] * mul) % mod) % mod;
                    }
                    else if(s[i-2]=='1' || s[i-2]=='2'){
                        int x = (s[i-2] - '0') * 10 + (s[i-1] - '0');
                        if(1<=x && x<=26){
                            dp[i] = (dp[i] + dp[i-2]) % mod;
                        }
                    }
                }
            }
        }
        return dp[n];
    }
};
```