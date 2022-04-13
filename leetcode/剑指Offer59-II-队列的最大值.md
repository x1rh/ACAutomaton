# 题目
[剑指 Offer 59 - II. 队列的最大值](https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/)


# 题意
实现一个队列，使得可以以均摊O(1)的代价`GetMax()`


# 思路
维护两个队列Q1和Q2，Q1存放所有入队的值，Q2存放单调递减的数。   

那么Q2中，队头元素即当前队列中的最大元素，若队头出队，则下一个是第二大的元素。    

Q2之所以可以成功记录最大元素，在于后入队的更大元素，可以将之前入队的较小的元素挤出队，因为最大值受后续入队的值影响。  


```go
type MaxQueue struct {
    data []int 
    maxl []int
}


func Constructor() MaxQueue {
    return MaxQueue{data: []int{}, maxl: []int{}}
}


func (this *MaxQueue) Max_value() int {
    if len(this.data) == 0 {
        return -1 
    } else {
        return this.maxl[0]
    }
}


func (this *MaxQueue) Push_back(value int)  {
    for len(this.maxl)!=0 && this.maxl[len(this.maxl)-1] < value {
        this.maxl = this.maxl[:len(this.maxl)-1]
    }

    this.data = append(this.data, value)
    this.maxl = append(this.maxl, value)

}


func (this *MaxQueue) Pop_front() int {
    if len(this.data) == 0 {
        return -1 
    }
    r := this.data[0]
    this.data = this.data[1:]
    if r == this.maxl[0] {
        this.maxl = this.maxl[1:]
    }
    return r 
}
```


