# 题目
`https://leetcode-cn.com/problems/sum-of-two-integers/`

# 思路
利用位运算，将一次加法拆分为`无进位的加法`和`进位`这两步，直到再无进位为止

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            unsigned int carry = static_cast<unsigned int>((a&b)) << 1;
            a = a^b;
            b = carry;
        }
        return a;
    }
};
```