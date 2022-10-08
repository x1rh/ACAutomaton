class CQueue {
public:
    stack<int> one, two;
    CQueue() {
        while(!one.empty()) one.pop();
        while(!two.empty()) two.pop();
    }
    
    void appendTail(int value) {
        one.push(value);    
    }
    
    int deleteHead() {
        if(one.empty()) return -1;
        while(!one.empty()){
            two.push(one.top()); 
            one.pop();
        }
        int ret = two.top();
        two.pop();
        while(!two.empty()){
            one.push(two.top());
            two.pop();
        }
        return ret;
    }
};