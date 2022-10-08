# 题目
`https://leetcode-cn.com/problems/random-pick-with-weight/`

# 思路
设区间长度为sum(w),使用randint，获取其中的一个数x，

再维护一个前缀和，二分查找x的位置即可


```python
class Solution:

    def __init__(self, w: List[int]):
        self.pre = list(accumulate(w))
        self.tot = sum(w)


    def pickIndex(self) -> int:
        x = random.randint(1, self.tot)
        return bisect_left(self.pre, x)
```