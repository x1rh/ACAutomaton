# 题目
`https://leetcode-cn.com/problems/latest-time-by-replacing-hidden-digits/`

# 思路
时间格式为h1h2:m1m2

- 其中h1和h2相互限制，而m1和m2相互独立
- h1为0和1时，h2可以为0到9，而h1为2时，h2只能为0到3
- h2为0到9时，h1只能为0到1



```cpp
class Solution {
public:
    string maximumTime(string time) {
        if(time[0] == '?'){
            if(time[1] == '?'){
                time[0] = '2';
                time[1] = '3';
            }
            else if(time[1]-'0' > 3){
                time[0] = '1';
            }
            else{
                time[0] = '2';
            }
        }
        if(time[1] == '?'){
            if(time[0] == '2'){
                time[1] = '3';
            }
            else{
                time[1] = '9';
            }
        }
        time[3] = time[3]=='?'?'5':time[3];
        time[4] = time[4]=='?'?'9':time[4];
        return time;
    }                                                                                
};
```