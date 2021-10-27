# 题目
`https://leetcode-cn.com/problems/remove-invalid-parentheses/`


# 思路
bfs，每层少一个括号


```cpp
class Solution {
public:
    bool check(string& s){
        stack<char> st;
        for(auto &x : s){
            if(x == '(') st.push('(');
            else if(x == ')'){
                if(st.empty()) return false;
                st.pop();
            }
        }
        return st.empty();
    }

    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        q.push(s);
        int ans_len = -1;
        unordered_map<string, bool> vis;
        vis[s] = true;
        vector<string> ans;

        while(!q.empty()){
            string fr = q.front();
            q.pop();
            if((ans_len!=-1) && fr.size() != ans_len){
                continue;
            }
            bool ok = check(fr);
            if(ok){
                if(ans_len == -1){
                    ans_len = fr.size();
                    ans.push_back(fr);
                    vis[fr] = true;
                    continue;
                }
                else if(fr.size() == ans_len){
                    ans.push_back(fr);
                    vis[fr] = true;
                    continue;
                }
                else{
                    continue;
                }
                
            }
            else{
                for(int i=0; i<fr.size(); ++i){
                    if(fr[i]!='(' && fr[i] != ')') continue;
                    string cur = fr.substr(0, i) + fr.substr(i+1, fr.size());
                    if(vis.find(cur) == vis.end()){
                        q.push(cur);
                        vis[cur] = true;
                    }
                }
            }
            


        }
        return ans;

    }
};
```