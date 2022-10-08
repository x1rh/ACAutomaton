# 题目
[868. 二进制间距](https://leetcode-cn.com/problems/binary-gap/)

# 题意
求一个数二进制形式下，两个相邻1的最大距离

# 思路
按题意实现即可


## 解法一：我的写法（挫）
```go
func binaryGap(n int) int {  
    b := []int{}
    for n > 0 {
        b = append(b, n%2)
        n /= 2
    }

    ans := 0
    n = len(b)
    for i,j:=0,0; j<n; j++{
        for i<n && b[i] != 1 {
            i++
        }
        if i>=n || b[i] !=1 {
            break 
        }

        j = i+1 
        for j<n && b[j] != 1 {
            j++
        }
        if j>=n || b[j] != 1 {
            break 
        }

        ans = max(ans, j-i)
        i = j 
    }
    return ans 
}

func max(x, y int) int {
    if x > y {
        return x 
    } else {
        return y 
    }
}
```

## 解法2：官方题解
```go
func binaryGap(n int) int {
    ans := 0
    for i,last:=0,-1; n>0; i,n = i+1,n/2 {
        if n%2 == 1 {
            if last != -1 {
                ans = max(ans, i-last) 
            }
            last = i 
        }
    }
    return ans 
}

func max(x, y int) int {
    if x > y {
        return x 
    } else {
        return y 
    }
} 
```