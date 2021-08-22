# 题目
`https://leetcode-cn.com/problems/generate-parentheses/`

# 思路
- 注意观察括号的形式，`()()()`, `(()())`

暴搜 + 合法性判断   
时间复杂度O((2^(2n))  * 2*n)  

```cpp
class Solution {
public:
    bool check(string& str){
        stack<char> s;
        for(int i=0; i<str.size(); ++i){
            if(str[i]=='('){
                s.push('(');
            }
            else{
                if(s.empty()) return false;
                char tp = s.top(); s.pop();
                if(tp != '(') return false;
            }
        }
        if(s.empty()) return true;
        else return false;
    }


    void dfs(vector<string>& ans, vector<char>& cur, int pos, int le, int ri){
        if(le<0 || ri<0) return;
        if(le==0 && ri==0){
            string retval(cur.begin(), cur.begin()+pos);
            if(check(retval)){
                ans.emplace_back(retval);
            }
        }
        cur[pos] = '(';
        dfs(ans, cur, pos+1, le-1, ri);
        cur[pos] = ')';
        dfs(ans, cur, pos+1, le, ri-1);
    }

    vector<string> generateParenthesis(int n) {
        vector<char> cur(2*n+1, 0);
        vector<string> ans;
        dfs(ans, cur, 0, n, n);
        return ans;
    }
};
```



