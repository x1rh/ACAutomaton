# 题目
``


# 思路


暴搜1：搜索每个单词是否在board中出现

30000 * 12*12 * 10 = 43200000  超时（即使剪枝）
```cpp
class Solution {
public:
    bool g;
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    void dfs(string& w, int idx, int x, int y, int turn, 
        vector<vector<pair<int, int>>>& sc, 
        vector<vector<int>>& vis,
        vector<vector<char>>& board
    ){
        if(g) return;
        if(idx == w.size()){
            g = true;
            return;
        }
        for(int i=0; i<4; ++i){
            int cx = dx[i] + x;
            int cy = dy[i] + y;
            if(0<=cx&&cx<board.size() && 0<=cy&&cy<board[0].size()){
                if(board[cx][cy]==w[idx] && vis[cx][cy]!=turn){
                    vis[cx][cy] = turn;
                    dfs(w, idx+1, cx, cy, turn, sc, vis, board);
                    vis[cx][cy] = turn - 1;
                }
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<pair<int, int>>> sc(26, vector<pair<int, int>>());
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                sc[board[i][j] - 'a'].emplace_back(i, j);
            }
        }


        vector<string> ans;
        for(int i=0; i<words.size(); ++i){
            if(words[i].size() > m*n) continue;

            for(int j=0; j<sc[ words[i][0] - 'a' ].size(); ++j){
                auto [x, y] = sc[ words[i][0] - 'a' ][j];
                g = false;
                vis[x][y] = i+1;
                dfs(words[i], 1, x, y, i+1, sc, vis, board);
                vis[x][y] = i;
                if(g){
                    ans.emplace_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
```

暴搜2： 从board的每一个点开始遍历，判断是否能找到word出现。

两个优化点，不写必t：
- str长度不超过10
- 从set中删除找到了的字符串

```cpp
class Solution {
public:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0}; 

    void dfs(
        vector<vector<char>>& board, int x, int y, 
        string& str, set<string>& s, set<string>& sa,
        vector<vector<bool>>& vis
    ){
        if(str.size()>10) return;
        if(s.size()==0) return;
        if(s.count(str)){
            sa.insert(str);
            s.erase(str);
        }
        
        for(int i=0; i<4; ++i){
            int cx = x + dx[i];
            int cy = y + dy[i];
            if(0<=cx&&cx<board.size() && 0<=cy&&cy<board[0].size() && !vis[cx][cy]){
                vis[cx][cy] = true;
                auto new_str = str + board[cx][cy];
                dfs(board, cx, cy, new_str, s, sa, vis);
                vis[cx][cy] = false;
            }
        }

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> s;
        for(auto &x : words){
            s.insert(x);
        }
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<string> ans;
        set<string> sa;

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                vis[i][j] = true;
                string str(1, board[i][j]);
                dfs(board, i, j, str, s, sa, vis);
                vis[i][j] = false;
            }
        }
        for(auto &x : words){
            if(sa.count(x)){
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```

# 解法3： trie
