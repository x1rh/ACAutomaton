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
    struct Node{
        int g[26];
        Node(){memset(g, 0, sizeof(g));}
    };
    vector<string> commonChars(vector<string>& A) {
        vector<Node> mp(A.size());
        vector<string> ans;
        for(int i=0; i<A.size(); ++i){
            for(int j=0; j<A[i].size(); ++j){
                mp[i].g[A[i][j]-'a'] += 1;
            }
        }
        for(int i=0; i<26; ++i){
            int _min = mp[0].g[i];
            for(int j=1; j<A.size(); ++j){
                if(_min > mp[j].g[i]){
                    _min = mp[j].g[i];
                }
            }
            if(_min){
                for(int j=0; j<_min; ++j){
                    ans.emplace_back(1, (char)('a'+i));
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<string> v({"bella","label","roller"});
    vector<string> ans = sol.commonChars(v);
    print(ans);
    return 0;
}