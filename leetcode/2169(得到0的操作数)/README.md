# 题目
- 280场周赛-第一题
- [2169. 得到 0 的操作数](https://leetcode-cn.com/problems/count-operations-to-obtain-zero/)


# 题意
两个数辗转相减，要求大的减小的，直到其中一个为0

# 思路
模拟即可

```cpp
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while(num1 && num2){
            if(num1 > num2){
                num1 -= num2;
            } else {
                num2 -=num1;
            }
            ++ans;
        }
        return ans;
    }
};

```
