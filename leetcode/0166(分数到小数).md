# 题目
`https://leetcode-cn.com/problems/fraction-to-recurring-decimal/`


# 思路
1. 判断正负。
   - 坑点，必须用n*d判断， 用n/d的话，0的时候丢失负号
   - n*d爆int
2. 整体思路：余数乘10模d，利用余数判断是否出现循环节
   - 坑点：对应关系保持一致，余数-小数位-下标
   - 处理循环节前的小数部分
   - 无循环节的情况

错了5发，我是sb

```cpp
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
    
        ostringstream oss;        

        long long n = numerator;
        long long d = denominator;
        
        if(n*d < 0) oss<<"-";
        n = abs(n);
        d = abs(d);
        
        long long a = floor(n/d);
        long long l = n%d;
        oss<<a;

        if(l==0){
            return oss.str();
        }
        else{
            oss<<".";
            map<int, int> mp;
            vector<int> v;
            bool flag = false;
            while(l!=0){
                int cur = floor(l*10/d);
                v.push_back(cur);
                mp[l] = v.size()-1;
                
                l = (l*10) % d;
                
                if(mp.find(l) != mp.end()){
                    for(int i=0; i<mp[l]; ++i){
                        oss<<v[i];
                    }
                    oss<<"(";
                    for(int i=mp[l]; i<v.size(); ++i){
                        oss<<v[i];
                    }
                    oss<<")";
                    return oss.str();
                }   
            }
            for(auto &x : v){
                oss<<x;
            }
            return oss.str();
        }
    }
};
```