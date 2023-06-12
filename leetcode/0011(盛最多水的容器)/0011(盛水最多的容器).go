package main;

func maxArea(height []int) int {
    var ans, min int 
    for l,r:=0,len(height)-1; l<r; {
        if height[l] < height[r] {
            min = height[l]
            l+=1
        } else {
            min = height[r]
            r-=1
        }
        ans = max(ans, (r-l+1) * min)
    }
    return ans
}


func max(x, y int) int {
    if x > y {
        return x 
    }
    return y 
}
