# 题目
`https://leetcode-cn.com/problems/additive-number/`

# 题意
判断一个字符串是否是abcd...， 其中a+b=c, b+c=d ...


# 思路
- 枚举第一个和第二个数即可
- 结合题目和范围，可知，一个数最长为14, unsigned long long刚好不会溢出
- 注意前导0，_(:зゝ∠)_， WA了4发。。。和为0当且仅当两个加数为0，此时和允许第一个字符为‘0’


```cpp
typedef unsigned long long ll;
class Solution {
public:
    bool check(string one, string two, string num){
        
        if(num.size()==0) return false;
        if(max(one.size(), two.size()) > num.size()) return false;

        ll A = str2ll(one);
        ll B = str2ll(two);
        
        if(A==-1 || B==-1) return false;
        if(num[0] == '0' && (A+B!=0)) return false;

        ll C = 0;
        bool last_one = false;
        for(int i=0; i<num.size(); ++i){
            if(C==0 && num[i]=='0' && (A+B!=0)) return false;
            C = C * 10 + (num[i]-'0');
            if(A+B == C){
                A = B;
                B = C;
                C = 0;
                if(i == num.size()-1) last_one = true; 
            }
        }
        if(last_one) return true;
        else{
            return A+B==C;
        }
    }

    ll str2ll(string x){
        ll ret = 0;
        for(auto &i : x){
            ret = ret * 10 + (i-'0');
        }
        if(ret != 0 && x[0] == '0') return -1;
        else return ret;
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();
        int duration = ceil(n/2);
        for(int i=0; i<duration; ++i){
            for(int j=i+1; j-i<=duration; ++j){
                if(check(num.substr(0, i-0+1), num.substr(i+1, j-i), num.substr(j+1))) return true;
            }
        }
        return false;
    }
};
```