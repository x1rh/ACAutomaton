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
    void duplicateZeros(vector<int>& arr) {
        vector<int> v;
        for(int i=0; i<arr.size(); ++i){
            if(arr[i]==0 && v.size()<arr.size()){
                v.push_back(0);
            }
            if(v.size()<arr.size())v.push_back(arr[i]);
        }
        arr.swap(v);
    }
};

int main(){
    Solution sol;
    vector<string> words({"cat","bt","hat","tree"});
    string chars("atach");
    cout<<sol.countCharacters(words, chars)<<endl;
    return 0;
}