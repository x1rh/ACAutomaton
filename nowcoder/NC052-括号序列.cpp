class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '(' || s[i] == '{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char tp = st.top();
                st.pop();
                if(tp=='(' && s[i]==')' ||
                   tp=='[' && s[i]==']' ||
                   tp=='{' && s[i]=='}'
                  ){
                    continue;
                }
                else{
                    return false;
                }
                    
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};