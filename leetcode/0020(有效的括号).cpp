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