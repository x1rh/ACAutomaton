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