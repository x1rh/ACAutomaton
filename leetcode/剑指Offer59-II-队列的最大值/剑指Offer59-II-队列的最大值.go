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