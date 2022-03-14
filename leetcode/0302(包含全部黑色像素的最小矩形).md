# 题目
[302. 包含全部黑色像素的最小矩形](https://leetcode-cn.com/problems/smallest-rectangle-enclosing-black-pixels/)

# 题意
图片内所有的黑色像素都连在一起，求一个最小的矩形的面积，能够包含所有的黑色像素

# 思路
- 设矩阵是m行n列，设答案矩阵上下左右为top、bottom、left、right
- 对矩阵向x轴和y轴投影，那么黑色将是连续的
- 二分满足的条件：
    - 对y轴的投影中，下标[0, x]中是递增的，表现为从'0'到'1'，求top时利用这一点，二分快速找到下标。在下标[x, m]中是递减的，表现为从'1'到'0'，求bottom时，使用二分快速找到下标
    - 对x轴的投影类似。
- 每次判断mid是否合法的代价为O(m) 或者O(n)
- 总的时间复杂度是O(mlog(n) + nlog(m))

```go
func searchTop(img [][]byte, l, r, n int) int {
    for ; l<=r; {   
        mid := (l+r)/2
        flag := false 
        for i:=0; i<n; i++ {
            if img[mid][i] == '1' {
                flag = true
                break 
            }
        }
        if flag {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }
    return l 
}

func searchBottom(img [][]byte, l, r, n int) int {
    for ; l<=r; {   
        mid := (l+r)/2
        flag := false 
        for i:=0; i<n; i++ {
            if img[mid][i] == '1' {
                flag = true
                break 
            }
        }
        if flag {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    return r 
}

func searchLeft(img [][]byte, l, r, n int) int {
    for ; l<=r; {
        mid := (l+r)/2
        flag := false 
        for i:=0; i<n; i++ {
            if img[i][mid] == '1' {
                flag = true 
                break 
            }
        }
        if flag {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }
    return l 
}

func searchRight(img [][]byte, l, r, n int) int {
    for ; l<=r; {
        mid := (l+r)/2
        flag := false 
        for i:=0; i<n; i++ {
            if img[i][mid] == '1' {
                flag = true 
                break 
            }
        }
        if flag {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    return r
}


func minArea(image [][]byte, x int, y int) int {
    m := len(image)
    n := len(image[0])

    top := searchTop(image, 0, x, n)
    bottom := searchBottom(image, x, m-1, n)
    left := searchLeft(image, 0, y, m)
    right := searchRight(image, y, n-1, m)

    // fmt.Println(top, bottom, left, right)
    return (bottom-top+1) * (right-left+1)
}
```