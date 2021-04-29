/*

注意别忘记了pop
*/

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty()){
            int top = stack1.top();
            stack1.pop();
            stack2.push(top);
                
        }
        int res = stack2.top();
        stack2.pop();
        while(!stack2.empty()){
            int top = stack2.top();
            stack2.pop();
            stack1.push(top);
        }
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};