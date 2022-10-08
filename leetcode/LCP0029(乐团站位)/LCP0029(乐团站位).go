func orchestraLayout(num int, x int, y int) int {
    l := 0
    r := num-1
    t := 0
    b := num-1 

    // 圈数
    loop := min(min(x-t, b-x), min(y-l, r-y))          


    // 计算完整的外层中一共有多少个人
    // 等差数列求和公式，(首项+末项)*项数/2，把里面的4和外面的2做了约分
    cnt := ((num-1)*2 + (num-(loop-1)*2-1)*2) * loop   


    // x, y 所在的圈的边长 edge len
    el := (num-loop*2-1) 

    toL := y-l-loop+1
    toT := x-t-loop+1
    toR := r-y-loop+1
    toB := b-x-loop+1

    // 判断在上下左右哪条边
    if 1<=toL && toL<=el && x-t==loop{
        cnt += toL
    } else if 1<=toT && toT<=el && r-y==loop {
        cnt += toT + el
    } else if 1<=toR && toR<=el && b-x==loop {
        cnt += toR + el*2
    } else if 1<=toB && toB<=el && y-l==loop {
        cnt += toB + el*3
    } else {
        cnt += 1  // 特判 样例为 3 1 1 这样的数据 即最里层
    }

    return (cnt-1) % 9 + 1
}

func min(x, y int) int {
    if x < y {
        return x 
    } else {
        return y 
    }
}
