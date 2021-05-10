#include <iostream>
#include <vector>

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
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int len = S.length();
        int i=0, j=0;
        while(i<len){
            j = i+1;
            while(j<len && S[j]==S[j-1]) ++j;
            if(j-i>=3){
                res.push_back(vector{i, j-1});
            }
            i = j;
        }
        return res;
    }
};

int main(){
    Solution sol;

    string s("abcdddeeeeaabbbcd");
    vector<vector<int>> res = sol.largeGroupPositions(s);
    print(res);
    return 0;
}