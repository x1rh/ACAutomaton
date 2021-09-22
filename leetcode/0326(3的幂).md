# 题目
`https://leetcode-cn.com/problems/power-of-three/`

# 思路

## 解法一：两边取对数，然后做一下简单运算即可。
- 时间复杂度O(1)

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        const double exp = 0.0000000001;
        double x = log(n) / log(3) * 1.0;
        int ix = x+exp;
        if(fabs(x-ix)<exp) return true;
        else return false;
    }
};
```

一个非常离谱的样例：
```cpp
243
```


```python
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False
        x = log2(n)/log2(3)
        ix = int(x)
        if abs(x-ix) <= 0.00000000001:
            return True
        else:
            return False
```

对于n=243,python算出x为5.0000.0005，而cpp是4.9999999x, cpp下取整后变4就出问题了。


## 方法2： 试除法
- 不断除3，看是否能除到1
- 时间复杂度log3(n)


## 方法3： 判断n是否为1162261467的约数
其中1162261467是(0, 2**31 -1] 范围内的最大的3的幂

