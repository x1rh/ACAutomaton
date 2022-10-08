class Solution {
public:
    set<int> se;
    bool flag;
    int sz;
    map<int, bool> mp;
    void dfs(vector<int>& vec, int x, int pos, int n){
        if(flag) return;

        vec[pos] = x;
        if(pos == sz-1){
            auto it = se.find(vec.back());
            if(it != se.end()){
                flag = true;
                return;
            }
        }
        else{
            int backup = x;
            for(int i=0; i<n; ++i){
                x = backup ^ (1<<(i));
                if(mp[x]){
                    continue;           
                }
                mp[x] = true;
                dfs(vec, x, pos+1, n);
                mp[x] = false;
            }
        }
    }

    vector<int> grayCode(int n) {
        sz = pow(2, n);
        se.clear();
        for(int i=0; i<n; ++i){
            se.insert(0 ^ (1<<(i)));
        }

        flag = false;
        vector<int> vec(sz, 0);
        mp[0] = true;
        dfs(vec, 0, 0, n);
        return vec;
    }
};