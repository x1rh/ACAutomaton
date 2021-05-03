/*
递归+回溯
注意处理重复字符串
*/

class Solution {
public:

    void dfs(vector<string> &ans, int idx, vector<char> &can, string &target, vector<bool> &vis){
        if(idx==can.size()){
            ans.push_back(target);
            return;
        }
        else{
            for(int i=0; i<can.size(); ++i){
                if(!vis[i]){
                    target[idx] = can[i];
                    vis[i] = true;
                    dfs(ans, idx+1, can, target, vis);
                    vis[i] = false;
                }
            }
        }
    }
    vector<string> Permutation(string str) {
        int sz = str.size();
        vector<char> can(sz);
        vector<bool> vis(sz);
        vector<string> ans;


        for(int i=0; i<str.size(); ++i){
            can[i] = str[i];
        }
        string target = string(sz, ' ');
        sort(can.begin(), can.end());
        dfs(ans, 0, can, target, vis);
        sort(ans.begin(), ans.end());
        auto len = unique(ans.begin(), ans.end()) - ans.begin();
        ans.resize(len);
        return ans;
    }
};
