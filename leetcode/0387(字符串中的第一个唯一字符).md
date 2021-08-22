# 题目
`https://leetcode-cn.com/problems/first-unique-character-in-a-string/`

# 思路
求字符串中第一个不重复的字符

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> om;
        for(int i=0; i<s.size(); ++i){
            om[s[i]] += 1;
        }
        for(int i=0; i<s.size(); ++i){
            if(om[s[i]] == 1) return i;
        }
        return -1;
    }
};
```