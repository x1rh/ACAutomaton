# 题目
`https://leetcode-cn.com/problems/valid-anagram/`


# 思路
判断两个字符串字符构成是否相同

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> ms;
        map<char, int> mt;
        for(int i=0; i<s.size(); ++i){
            ms[s[i]] += 1;
        }
        for(int i=0; i<t.size(); ++i){
            mt[t[i]] += 1;
        }
        if(ms.size() != mt.size()) return false;

        for(auto &[k, v] : ms){
            if(v != mt[k]){
                return false;
            }
        }
        return true;
    }
};
```



