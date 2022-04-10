# 题目
[1151. 最少交换次数来组合所有的 1](https://leetcode-cn.com/problems/minimum-swaps-to-group-all-1s-together/)

# 题意
一个0和1组成的数组，求最小交换次数，使得所有的1连续。

# 思路
滑动窗口：  
- 设所有1的个数是cnt，那么这题可以转换为，求所有长度为cnt的窗口中，0个数最少的那个窗口。而这个窗口内0的个数就是答案


```go
func minSwaps(data []int) int {
    n := len(data)
    one := 0 
    for i := range data {
        if data[i] == 1 {
            one += 1 
        }
    }
    if one == 0 {
        return 0 
    }

    ans := 0x3f3f3f3f
    cnt := 0
    for i, j:=0, 0; j<n; j++{
        if data[j] == 0 {
            cnt += 1 
        } 

        for j-i+1 > one {
            if data[i] == 0 {
                cnt -= 1 
            }
            i += 1 
        }

        if j-i+1 == one && cnt < ans {
            ans = cnt 
        }
    }
    return ans 
}
```