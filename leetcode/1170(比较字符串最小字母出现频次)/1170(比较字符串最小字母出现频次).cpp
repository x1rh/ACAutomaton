#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;

template <typename T>
void print(vector<T>& v){
    for(auto it=v.begin(); it!=v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

template<typename T>
void print(vector<vector<T>>& v){
    for(auto iti=v.begin(); iti!=v.end(); ++iti){
        for(auto itj=(*iti).begin(); itj!=(*iti).end(); ++itj){
            cout<<*itj<<" ";
        }
        cout<<endl;
    }
}

class Solution {
public:
    int f(string& s){
        if(s.length() == 0) return 0;
        char _min = s[0];
        int ans = 0;
        for(int i=1; i<s.length(); ++i){
            _min = min(_min, s[i]);
        }
        for(int i=0; i<s.length(); ++i){
            if(s[i] == _min) ++ans;
        }
        return ans;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> mp(words.size());
        vector<int> ans(queries.size());
        for(int i=0; i<words.size(); ++i){
            mp[i] = f(words[i]);
        }
        sort(mp.begin(), mp.end());
        for(int i=0; i<queries.size(); ++i){
            int cnt = f(queries[i]);
            auto it = upper_bound(mp.begin(), mp.end(), cnt);
            if(it!=mp.end()){
                ans[i] = distance(it, mp.end());
            }
            else ans[i] = 0;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<string> queries({"bbb","cc"});
    vector<string> words({"a","aa","aaa","aaaa"});
    vector<int> ans = sol.numSmallerByFrequency(queries, words);
    print(ans);
    return 0;
}