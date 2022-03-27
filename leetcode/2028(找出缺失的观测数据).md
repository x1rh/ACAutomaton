# 题目
[2028. 找出缺失的观测数据](https://leetcode-cn.com/problems/find-missing-observations/)


# 题意
n+m个色子的平均值是mean，已知m个色子，求剩余n个色子的可能值


# 思路： 构造
- 判断合法
- 求n个值的均值，然后将模的结果（余数）均分给数组前面的项

```go
func missingRolls(rolls []int, mean int, n int) []int {
    m := len(rolls)
    ans := make([]int, n)
    sum := 0 
    for i := range rolls {
        sum += rolls[i] 
    }

    cnt := (n+m)*mean - sum 

    if cnt < n || cnt>6*n {
        return []int{}
    }

    x, y := cnt/n, cnt%n 

    for i := range ans {
        ans[i] = x 
        if i < y {
            ans[i] += 1 
        }
    }
    return ans 
}
```