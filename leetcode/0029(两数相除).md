# 题目
`https://leetcode-cn.com/problems/divide-two-integers/`

# 思路
要求：
- 不可以用乘法、除法、模的情况下，实现int类型的除法。
- 不能使用long long,
- 除法结果溢出，返回INT_MAX.

思路：
1. 转换为两个负数的除法。（因为负数的范围更大）
2. 利用二分查找商
3. 实现`快乘`（类似于快速幂）
4. 二分查找中一堆溢出问题（二分中有额外的返回值标明是否溢出，溢出则标明当前mid太大）
5. 特判两个情况。

```cpp

class Solution {
public:

    tuple<int, int> fast_multiple(int a, int b){
        int retval = 0;
        while(b){
            if(b&1){
                if(retval < INT_MIN - a){
                    return {false, INT_MIN};
                }
                retval += a;
                b -= 1;
            }
            else{
                b >>= 1;
                b -= 1;
                if(a < INT_MIN-a){
                    return {false, INT_MIN};
                }
                a += a;
                if(retval < INT_MIN - a){
                    return {false, INT_MIN};
                }
                retval += a;
            }
        }
        return {true, retval};
    }

    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN){
            if(divisor==-1)
                return INT_MAX;
            if(divisor==1)
                return INT_MIN;
        }
        if(divisor == INT_MIN){
            if(dividend == INT_MIN){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dividend == 0) return 0;

        bool flag = false;
        if(dividend>0 && divisor<0){
            flag = !flag;
        }
        else if(dividend<0 && divisor>0){
            flag = !flag;
        }
        if(dividend > 0){
             dividend = -dividend;
        }
        if(divisor > 0){
            divisor = -divisor;
        }


        int l=1, r=INT_MAX;
        while(l<=r){
            
            int mid = (l + ((r-l)>>1));
            auto [r1, r2] = fast_multiple(divisor, mid);
            // cout<<l<<" "<<r<<" "<<mid<<" "<<res<<endl;
            if(!r1){
                r = mid -1;
            }
            else if(r2 == dividend){
                r=mid;
                break;
            }
            else if(r2 < dividend){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }


        return flag==true?-r:r;

    }
};
```