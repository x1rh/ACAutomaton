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