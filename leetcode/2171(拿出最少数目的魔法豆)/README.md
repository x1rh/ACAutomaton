# 题目
- 第280场周赛-第3题
- [2171. 拿出最少数目的魔法豆](https://leetcode-cn.com/problems/removing-minimum-number-of-magic-beans/)

# 题意
给一个整数数组，你可以对某个数x变为0，代价是x，也可以将其变为y， 代价是x-y，x>=y>=0， 求变化后所有非0数都相同的最小代价。


# 思路
- 排序+前缀和
- 选定一个下标i，这小于i的数全部清空为0，后面的数全部修剪为num[i]，利用前缀和思想避免重复计算。

```python
class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        li = sorted(beans)
        pre = [0]
        i = 1
        for i in range(1, len(li)+1):
            pre.append(pre[-1]+li[i-1])
        
        minv = 1000000000000
        for i in range(0, len(li)):
            now = pre[-1] - pre[i+1]  - li[i] * (len(li)-1-i) + pre[i]
            minv = min(now, minv)
        
        return minv
```

ps: 看到数这么大，不想判断溢出，直接拿py写，minv随手输入了很多个0，但没细数，没想到居然还不够大，WA了一发....