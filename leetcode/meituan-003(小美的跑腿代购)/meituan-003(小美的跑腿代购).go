package main 

import (
    "fmt"
    "sort"
    "strconv"
    "strings"
)

type pair struct {
    v, i int 
}

func main() {
    var m, n, v, w int 

    fmt.Scanf("%v %v", &m, &n)

    arr := make([]pair, m)

    for i := 0; i < m; i++ {
        fmt.Scanf("%v %v", &v, &w)
        arr[i].v = v + w * 2 
        arr[i].i = i + 1
    }

    sort.Slice(arr, func(i, j int) bool {
        return arr[i].v > arr[j].v || (arr[i].v == arr[j].v && arr[i].i < arr[j].i)  
    })

    arr = arr[0:n]
    sort.Slice(arr, func(i, j int) bool {
        return arr[i].i < arr[j].i 
    })

    ans := make([]string, n)
    for i := 0; i < n; i++ {
        ans[i] = strconv.Itoa(arr[i].i)
    }

    fmt.Printf("%s ", strings.Join(ans, " "))  
}