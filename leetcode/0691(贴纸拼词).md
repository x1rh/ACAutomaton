# 题目
[691. 贴纸拼词](https://leetcode.cn/problems/stickers-to-spell-word/)

# 题意
n个单词，用每个单词中的字符拼凑一个target单词，每个单词可以使用任意次，求最少单词使用数。


# 思路
- dp + 二进制枚举
- 设`n=len(target)`， 则一共有`2^n`个状态。
- 设`f[i]`表示到达状态`i`所需要的最少单词数，那么我们对每个`f[i]`，让它和每个单词进行状态转移即可
- 转移方程是`f[next] = min(f[next], f[i]+1)`


```go
func minStickers(stickers []string, target string) int {
    m := len(stickers)
    n := len(target)
    cnt := make([][]int, m)
    for i := 0; i < m; i++ {
        cnt[i] = make([]int, 26)
        for j := 0; j < len(stickers[i]); j++ {
            cnt[i][stickers[i][j] - 'a'] += 1 
        }
    }

    maxn := 1<<n; 
    inf := 0x3f3f3f3f 
    f := make([]int, maxn)
    for i:=0; i<maxn; i++ {
        f[i] = inf 
    }
    f[0] = 0  
    for i := 0; i < maxn; i++ {
        if f[i] != inf {
            for j := 0; j < m; j++ {
                next := i 
                c := make([]int, 26)
                copy(c, cnt[j])
                for k := 0; k < n; k++ {
                    if (i>>k) & 1 == 0 && c[target[k]-'a'] > 0 {
                        c[target[k]-'a'] -= 1 
                        next ^= 1<<k                    
                    }
                }
                if f[next] > f[i] + 1 {
                    f[next] = f[i] + 1 
                }
            }
        }
    }
    if f[maxn-1] == inf {
        return -1 
    } else {
        return f[maxn-1]
    }
}
```