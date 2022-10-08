# 题目
`https://leetcode-cn.com/problems/excel-sheet-column-number/`

# 思路

26进制转换，进制转换时，注意从高位遍历到低位  

此外，傻逼题目，描述不清，溢出了

```cpp
class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ans = 0;
        for(int i=0; i<columnTitle.size(); ++i){
            ans = ans * 26 + (columnTitle[i] - 'A') + 1;
        }
        return ans;
    }
};
```
