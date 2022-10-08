# 题目
`https://leetcode-cn.com/problems/ransom-note/`

# 思路
判断字符串A是否可以由字符串B中的字符组成


```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mm;
        for(int i=0; i<magazine.size(); ++i){
            mm[magazine[i]] += 1;
        }
        
        for(int i=0; i<ransomNote.size(); ++i){
            if(mm[ransomNote[i]] >= 1){
                mm[ransomNote[i]] -= 1;
            }
            else return false;
        }
        return true;

    }
};
```

