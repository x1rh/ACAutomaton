# 题目
`https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/`

# 题意
求字符串s的子序列所能构成的单词word_i中，最长的那个单词。

单词来自一个字典。


# 思路
暴力枚举即可。这题不是最长公共子序列，直接判断字符串s的子序列能否构成word_i即可。

```cpp
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(auto &x : dictionary){
            int i=0, j=0;
            while(i<x.size() && j<s.size()){
                if(x[i]==s[j]){
                    ++i; ++j;
                }
                else{
                    ++j;
                }
            }
            if(i==x.size()){
                if(x.size() > ans.size()) ans = x;
                else if(x.size()==ans.size() && x<ans) ans = x; 
            }
        }
        return ans;
    }
};
```

