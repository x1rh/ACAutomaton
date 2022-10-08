class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        sort(spaces.begin(), spaces.end());
        ostringstream oss;
        int idx = 0;
        if(spaces.size() == 0) return s;
        
        for(int i=0; i<s.size(); ++i){
            
            if(idx<spaces.size() && i == spaces[idx]){
                oss<<" ";
                ++idx;
            }
            oss<<s[i];
        }
        return oss.str();
    }
};