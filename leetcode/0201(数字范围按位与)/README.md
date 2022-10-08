# 题目
`https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/`


# 思路
求区间内所有数相与的结果，等价于求区间内所有数的二进制形式的公共前缀，等价于求left和right二进制形式下的公共前缀  


解法1： 右移，直到left等于right，然后再左移

```cpp
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 1;
        while(left != right){
            left >>= 1;
            right >>= 1;
            cnt  <<= 1;
        }
        return left * cnt;
    }
};
```

解法2： Brian Kernighan 算法

这个算法每次清空一个数二进制位的最右边一位。
注意return的是right
```cpp
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left < right){
            right = right & (right-1);
        }
        return right;
    }
};
```