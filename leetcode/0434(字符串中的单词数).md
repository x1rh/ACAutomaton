# 题目
`https://leetcode-cn.com/problems/number-of-segments-in-a-string/`


# 思路
统计以空格相隔的单词的个数

```cpp
class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        s.lstrip()
        s.rstrip()
        t = s.split()
        return len(t)
```