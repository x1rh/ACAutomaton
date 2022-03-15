# 题目
[1231. 分享巧克力](https://leetcode-cn.com/problems/divide-chocolate/)

# 题意
一个数组，每个元素表示甜度，要求分成k+1个连续的子序列，使得最小的那一份最大，设为ans。


# 思路
- 经过思考，可以知道ans的取值范围是[0, sum(sweetness)/(k+1)], 在这个单调的区间上做二分。
- 每次check mid的思路也很简单：
    - 用最少的巧克力组成大于或等于mid的甜度
    - 最后如果份数大于或等于sum(sweetness)/(k+1)，则可以认为mid偏小，反之同理。


```go
func check(arr []int, avg int) int {
    
    cnt := 0 
    cur := 0 

    for i := range arr {
        cur += arr[i] 
        if cur >= avg {
            cnt += 1
            cur = 0 
        }
    }
    return cnt 
}


func maximizeSweetness(sweetness []int, k int) int {
    sum := 0

    for i := range sweetness {
        sum += sweetness[i]
    }

    l := 0 
    r := sum / (k+1)

    for ; l <= r ; {
        mid := (l+r)/2
        if check(sweetness, mid) >= k+1 {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }

    return r
}
```