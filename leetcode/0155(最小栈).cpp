#include <iostream>
#include <stack>
#include <queue>
#include <list>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    list<int> L;
    MinStack() {

    }

    void push(int x) {
        L.push_front(x);
    }

    void pop() {
        L.pop_front();
    }

    int top() {
        return *L.begin();
    }

    int getMin() {
        int _min = *L.begin();
        auto it = L.begin();
        ++it;
        while(it!=L.end()){
            if(*it < _min) _min = *it;
            ++it;
        }
        return _min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main(){


    cout<<pq.top()<<endl;

    return 0;
}