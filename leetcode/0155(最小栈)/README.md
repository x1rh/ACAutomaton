# 题目
[155. 最小栈](https://leetcode-cn.com/problems/min-stack/)

# 题意
实现一个栈，要求能O(1)获得最小值


# 思路1. 辅助栈，空间开销O(N)

利用当前的最小值肯定在top之下这一前提，很容易维护每一个栈元素位置及之前的最小值


```go
type MinStack struct {
    data, min []int 
}


func Constructor() MinStack {
    return MinStack{data: []int{}, min: []int{}}
}


func (this *MinStack) Push(val int)  {
    if len(this.data) > 0 {
        if val <= this.min[len(this.min)-1] {
            this.min = append(this.min, val)
        }
        this.data = append(this.data, val)
    } else {
        this.min = append(this.min, val)
        this.data = append(this.data, val)
    }
    
    
}


func (this *MinStack) Pop()  {
    if len(this.data) > 0 {
        if this.data[len(this.data)-1] == this.min[len(this.min)-1] {
            this.min = this.min[:len(this.min)-1]
        }
        this.data = this.data[:len(this.data)-1]
    }
}


func (this *MinStack) Top() int {
    return this.data[len(this.data)-1]
}


func (this *MinStack) GetMin() int {
    return this.min[len(this.min)-1]
}
```


# 思路2：存差，实现空间O(1)
只要明白存的是和最小值的差，那么便很容易一步步推导出后续的写法（ps：还是非常容易写疵）

```go
type MinStack struct {
    v []int 
    min int 
}


func Constructor() MinStack {
    return MinStack{v :[]int{}, min: 0}
}


func (this *MinStack) Push(val int)  {
    if len(this.v) > 0 {
        if this.min >= val {
            this.v = append(this.v, val-this.min)
            this.min = val 
        } else {
            this.v = append(this.v, val-this.min)
        }
    } else {
        this.min = val 
        this.v = append(this.v, 0)
    }
}


func (this *MinStack) Pop()  {
    if len(this.v) > 0 {
        top := this.v[len(this.v)-1] 
        if top <= 0 {
            this.min -= top 
        } 
        this.v = this.v[:len(this.v)-1]
    }
}


func (this *MinStack) Top() int {
    top := this.v[len(this.v)-1]
    if top <= 0 {
        return this.min 
    } else {
        return this.min + top 
    }
}


func (this *MinStack) GetMin() int {
    return this.min 
}
```
