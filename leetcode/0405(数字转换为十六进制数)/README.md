# 题目
`https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/`

# 思路

转无符号数，然后辗转相除即可。
`注意特判0`

```cpp
class Solution {
public:
    char con(int x){
        if(x<10){
            return '0' + x;
        }
        else{
            return 'a' + x - 10;
        }
    }

    string toHex(int num) {
        if(num==0) return "0";
        
        string ans;
        uint32_t k = num;

        while(k){
            ans = con(k % 16) + ans;
            k /= 16;
        }
        return ans;
    }
};
```


## 解法2 使用格式化输出

```cpp
class Solution {
public:
    string toHex(int num) {
        ostringstream oss;
        oss<<hex<<num;
        return oss.str();
    }
};
```