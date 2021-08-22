# 题目
`https://leetcode-cn.com/problems/valid-parentheses/`

# 思路
- 遇到左括号入栈，遇到右括号，弹出栈顶元素进行比较
- 注意事项：
  - 当前读到右括号，栈空，则为false
  - 遍历完成后栈不空，为false

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char tp = st.top(); st.pop();
                if(s[i]==')' && tp!='(') return false;
                if(s[i]==']' && tp!='[') return false;
                if(s[i]=='}' && tp!='{') return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
```


# 以前写的
```cpp
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length()==0) return true;
        stack<char> st;
        for(int i=0; i<s.length(); ++i){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char tp = st.top();
                if(s[i]==')' && tp=='('){
                    st.pop();
                }
                else if(s[i]==']' && tp=='['){
                    st.pop();
                }
                else if(s[i]=='}' && tp=='{'){
                    st.pop();
                }
                else return false;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};

int main(){
    Solution sol;
    cout<<sol.isValid("()")<<endl;

    return 0;
}
```