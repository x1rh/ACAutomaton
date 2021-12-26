# 题目
https://leetcode-cn.com/problems/occurrences-after-bigram/


# 题意
给一段文本，求以first + 空格 + second 开头的子串中的third


# 思路
遍历一遍并判断即可。
```python
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        ans = list()
        spl = text.split()
        for i, x in enumerate(spl):
            if i <= len(spl) - 3:
                if spl[i] == first and spl[i+1] == second:
                    ans.append(spl[i+2])


        return ans  

```
