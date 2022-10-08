# 题目
[838. 推多米诺](https://leetcode-cn.com/problems/push-dominoes/)

# 题意
给定多米诺骨牌初始时的状态，求最后状态

# 思路
模拟，细节：
- `L...R`的最终状态为：`LL.RR`
- `LL.R`的最终状态为：`LL.R`
- `R...`的最终状态为：`RRRR`
- 模拟时注意同时与逐步的区别

Go
```go
func pushDominoes(dominoes string) string {
    n := len(dominoes)
    v := make([]int, n)
    for i:=0; i<n; i++ {
        if dominoes[i] == 'L' {
            v[i] += -1;
        } else if dominoes[i] == 'R' {
            v[i] += 1;
        }
    }

    for i:=0; i<n-1; {
        if dominoes[i] == 'R' && dominoes[i+1] == '.'{
            var j int 
            for j=i+1; j<n && dominoes[j] == '.'; j++ {};

            if j==n || dominoes[j] == 'R' {
                for k:=i+1; k<j; k++ {
                    v[k] += 1
                }
            } else {
                for k:=i+1; k<i+(j-i+1)/2; k++ {
                    v[k] += 1
                }
            }
            i = j;
        } else {
            i += 1;
        }
        
    }

    for i:=n-1; i>=1;{
        if dominoes[i] == 'L' && dominoes[i-1] == '.'{
            var j int 
            for j=i-1; j>=0 && dominoes[j] == '.'; j-- {};
            if j == -1 || dominoes[j] == 'L' {
                for k:=i-1; k>j; k-- {
                    v[k] += -1;
                }    
            } else {
                for k:=i-1; k>i-(i-j+1)/2; k-- {
                    v[k] += -1;
                }
            }
            i = j;
        } else {
            i -= 1;
        }
    }

    ans := make([]byte, n)

    for i:=0; i<n; i++ {
        if v[i] == 0 {
            ans[i] = '.'
        } else if v[i] == -1 {
            ans[i] = 'L'
        } else {
            ans[i] = 'R'
        }
    }

    return string(ans)
}
```

时间复杂度：O(n), 常数大了些  
空间复杂度：O(n)

## 官方题解
看了一下，题解是根据`.`的状态来做的，而我是根据`L`和`R`来做的，写起来非常痛苦