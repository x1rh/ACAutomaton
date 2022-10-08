# 题目
[5253. 找到指定长度的回文数](https://leetcode-cn.com/u/lrhaoo/)

# 题意
求第i个长度为len的回文数是什么


# 思路

设回文数`x=LR`，例如`x=12321`时，那么`L=123`，`R=321`

对于长度为intLength的回文数，其第i个回文数的L是什么？

对于长度为3的回文数：
第1个数是`101 ->  1+9=10 -> 10 01 -> 101`
第11个数是`111 -> 11+9=20 -> 20 02 -> 202`
第90个数是`999 -> 90+9=99 -> 99 99 -> 999`

对长度为5的回文数：
第一个数是`10001 -> 1+99=100 -> 100 001 -> 10001`
....


显然待求回文数的L等于i加上一个相同的偏移量x。

稍加思考也可以知道，这个偏移量产生的原因是，回文数开头不能为0，回文数第一个数必须从1开始。若从0开始，那么就会有000，而不是101这样的结果。为了达到一个从1开头的效果，必须加上一个`(10^j)-1`的偏移量


```python
class Solution:
    def kthPalindrome(self, q: List[int], il: int) -> List[int]:
        ans = list()
        
        t = [0] * 16
        for i in range (1, 16):
            t[i] = 10**((i-1)//2)-1
        
        for x in q:
            y = x + t[il]
    
            l = list(str(y))
            r = l[::-1]
            if il & 1:
                r = r[1:]
            
            l.extend(r)
            if len(l) == il:
                ans.append(int("".join(l)))
            else:
                ans.append(-1)

        return ans
```