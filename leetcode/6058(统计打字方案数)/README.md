# 题目
[6058. 统计打字方案数](https://leetcode-cn.com/problems/count-number-of-texts/)

# 题意
原问题：长度为n的字符串，切分成连续的1、2、3、4个子串，最多有多少种切分方法？


# 思路
设`f[i]`表示长度为i的字符串的切分方法，那么：
- `f[i] = f[i-1] + f[i-2] + f[i-3]` 字符串的值不等于7和9
- `f[i] = f[i-1] + f[i-2] + f[i-3] + f[i-4]`  字符串的值等于7或9时才有4这种情况
- `i>=0` 
- `f[0] = 1`


```go
func countTexts(press string) int {
    n := len(press)
    mod := int(1e9+7)
    
    cal := func(n, k int) int {
        f := make([]int, n+1)
        f[0] = 1 
        for i:=1; i<=n; i++ {
            for j:=1; j<=k; j++ {
                if i-j >= 0 {
                    f[i] = (f[i] + f[i-j]) % mod 
                }
            }
        }
        return f[n]
    }
    
    ans := 0
    t := 0
    for i,j:=0,0; i<n; i=j{
        for j=i; j<n&&press[i]==press[j]; j++ {}
        if press[i] == '7' || press[i] == '9' {
            t = cal(j-i, 4)
        } else {
            t = cal(j-i, 3)
        }     
        if ans == 0 {
            ans = t 
        } else {
            ans = (ans*t) % mod  
        }
    }
    return ans 
}

```
