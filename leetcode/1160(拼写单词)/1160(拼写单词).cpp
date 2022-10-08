#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
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
    int countCharacters(vector<string>& words, string chars) {
        vector<int> mp(26, 0);
        sort(words.begin(), words.end());
        for(int i=0; i<chars.length(); ++i){
             mp[chars[i]-'a'] += 1;
        }
        vector<int> backup = mp;
        int ans = 0;
        bool flag = false;
        for(int i=0; i<words.size(); ++i){
            flag = false;
            for(int j=0; j<words[i].length(); ++j){
                if(mp[words[i][j]-'a']-- == 0){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans += words[i].length();
            }
            mp = backup;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<string> words({"cat","bt","hat","tree"});
    string chars("atach");
    cout<<sol.countCharacters(words, chars)<<endl;
    return 0;
}