class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> rs(s.size());
        vector<char> rt(t.size());
        int idx = 0;
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='#'){
                if(idx>0) --idx;
            }
            else{
                rs[idx++] = s[i]; 
            }
        }
        int idy = 0;
        for(int i=0; i<t.size(); ++i){
            if(t[i]=='#'){
                if(idy>0) --idy;
            }
            else{
                rt[idy++] = t[i];
            }
        }
        if(idx != idy) return false;
        for(int i=0; i<idx; ++i){
            if(rs[i] != rt[i]) return false;
        }
        return true;

    }
};