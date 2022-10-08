class Solution {
private:
    vector<string> mp = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
public:
    void dfs(vector<string>& ans, string& digits, string& cur, int idx){
        if(idx >= digits.size()){
            ans.emplace_back(string(cur.begin(), cur.begin()+idx));
            return;
        }
        int x = digits[idx]-'0';
        for(int i=0; i<mp[x].size(); ++i){
            cur[idx] = mp[x][i];
            dfs(ans, digits, cur, idx+1);
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        string cur(digits.size()+1, ' ');
        dfs(ans, digits, cur, 0);
        return ans;
    }
};