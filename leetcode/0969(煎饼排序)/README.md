# 题目



# 题意
将一个随机数组排序，排序的方法是执行多次reversed(arr[0...k_i-1])，求ki序列

# 思路
- 题目没有要求最少操作数，只要求了可行
- 所以利用reverse_k 的特点，每次找到剩余数里最大的，稳定的将其reverse到末尾即可。
- 操作次数固定为(n-1)*2



python
```python
class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        
        li = sorted(arr, reverse=True)

        ans = list()

        for i, x in enumerate(li):
            jj = 0
            if i == len(li)-1:
                break 
            for j in range(0, len(li)-i):
                if arr[j] == x:
                    jj = j
                    break 
            
            arr = arr[0:j+1][::-1] + arr[j+1:len(li)-i]     
            arr = arr[::-1]
            ans.append(j+1)
            ans.append(len(arr))
        
        return ans 
```

Go
```go
func revserse(arr []int) []int {
    for i, j := 0, len(arr)-1; i<j; i, j = i+1, j-1{
        arr[i], arr[j] = arr[j], arr[i]
    }
    return arr 
}

func pancakeSort(arr []int) []int {
    n := len(arr)
    dst := make([]int, n)
    copy(dst, arr)
    sort.Slice(dst, func(i, j int)bool {return dst[i] < dst[j]}) 
    var ans []int

    for i:=0; i<n-1; i++ {
        max := dst[n-i-1]
        idx := 0
        for j:=0; j<n-i; j++ {
            if arr[j] == max {
                idx = j
                break 
            }
        }

        revserse(arr[0:idx+1])
        revserse(arr[0:n-i])
        ans = append(ans, idx+1)
        ans = append(ans, n-i) 
    }
    return ans 
}
```