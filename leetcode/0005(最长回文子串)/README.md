# 题目
`https://leetcode-cn.com/problems/longest-palindromic-substring/`


# 思路

回文串存在两种情况，如aba和aa。采用O(n^2)复杂度的遍历发，从中间往两边遍历，即可    

注意处理细节

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 1;
        int ai=0, aj=0;

        for(int i=0; i<s.size(); ++i){
            int l = i-1;
            int r = i+1;
            if(l>=0 && r<s.size() && s[l]==s[r]){
                while(l>=0 && r<s.size() && s[l]==s[r]){
                    --l;
                    ++r;
                }
                if(ans < r-l-1){
                    ans = r-l-1;
                    ai = l+1;
                    aj = r-1;
                }
            }
        }
        

        for(int i=1; i<s.size(); ++i){
            if(s[i-1]==s[i]){
                int l = i-1;
                int r = i;
                if(l>=0 && r<s.size() && s[l]==s[r]){
                    while(l>=0 && r<s.size() && s[l]==s[r]){
                        --l;
                        ++r;
                    }
                    if(l==i-1 && r==i && ans<r-l+1){
                        ans = 2;
                        ai = i-1;
                        aj = i;
                    }
                    else if(ans < r-l-1 ){
                        ans = r-l-1;
                        ai = l+1;
                        aj = r-1;
                    }
                }
                
            }
        }

        return string(s.begin()+ai, s.begin()+aj+1);
    }
};
```