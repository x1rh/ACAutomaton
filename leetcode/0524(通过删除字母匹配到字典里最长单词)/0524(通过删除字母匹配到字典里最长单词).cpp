class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(auto &x : dictionary){
            int i=0, j=0;
            while(i<x.size() && j<s.size()){
                if(x[i]==s[j]){
                    ++i; ++j;
                }
                else{
                    ++j;
                }
            }
            if(i==x.size()){
                if(x.size() > ans.size()) ans = x;
                else if(x.size()==ans.size() && x<ans) ans = x; 
            }
        }
        return ans;
    }
};