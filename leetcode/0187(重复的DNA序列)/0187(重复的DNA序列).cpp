class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> ans;
        if(n<10) return ans;
        string ts = s.substr(0, 10);
        map<string, int> mp;
        mp[ts] = 1;
        for(int i=10; i<n; ++i){
            ts = ts.substr(1, 9) + s[i];
            auto it = mp.find(ts);
            if(it != mp.end()){
                if(it->second == 1){
                    ans.push_back(it->first);
                    it->second += 1;
                }
            }
            else{
                mp[ts] = 1;
            }
        }
        return ans;
    }
};