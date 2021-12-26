# 题目
https://leetcode-cn.com/problems/string-without-aaa-or-bbb/


# 题意
要求随机生成一个字符串，要求这个字符串有a个'a'和b个'b'， 且生成的字符串中不能出现子串`aaa`和`bbb`


# 思路
首先题目保证每个输入都是有合法解的，利用这一点，设a>b, 则我们每两个a放一个b，生成aab这样的字符串。这样的话消耗b是最少的，并且这样重复操作后，a绝对被全部消耗完了。之后我们只需要把b放入合适的位置即可，我采用的策略是逢a放b。


```cpp
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        ostringstream oss;
        int A, B;
        char x, y;

        if(a>=b){
            A = a;
            B = b;
            x = 'a';
            y = 'b';            
        }
        else{
            A = b;
            B = a;
            x = 'b';
            y = 'a';
        }

        while(A){
            for(int i=0; i<2 && A>0; ++i){
                oss<<x;
                --A;
            }
            if(B){
                oss<<y;
                --B;
            }
            
        }
        if(B){
            ostringstream oss2;
            string t = oss.str();
            for(auto &i : t){
                oss2<<i;
                if((x==i) && B>0){
                    oss2<<y;
                    --B;
                }
            }
            return oss2.str();
        }
        else 
            return oss.str();
    }
};

```