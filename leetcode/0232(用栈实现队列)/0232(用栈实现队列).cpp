class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> one, two;

    MyQueue() {
        while(!this->one.empty()) this->one.pop();
        while(!this->two.empty()) this->two.pop();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        this->one.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!this->one.empty()){
            int tp = this->one.top(); 
            this->one.pop();
            this->two.push(tp);
        }
        int retval = this->two.top();
        this->two.pop();
        while(!this->two.empty()){
            int tp = this->two.top();
            this->two.pop();
            this->one.push(tp);
        }
        return retval;
    }
    
    /** Get the front element. */
    int peek() {
        while(!this->one.empty()){
            int tp = this->one.top(); 
            this->one.pop();
            this->two.push(tp);
        }
        int retval = this->two.top();
        while(!this->two.empty()){
            int tp = this->two.top();
            this->two.pop();
            this->one.push(tp);
        }
        return retval;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return this->one.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */