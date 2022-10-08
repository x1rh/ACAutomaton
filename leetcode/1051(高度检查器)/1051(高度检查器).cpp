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
        int val, idx;
        Node(){}
        Node(int val, int idx):val(val), idx(idx){}
        bool operator<(const Node& rhs){
            return val < rhs.val;
        }
    };
    int heightChecker(vector<int>& heights){
        vector<Node> v(heights.size());
        for(int i=0; i<heights.size(); ++i){
            v[i].val = heights[i];
            v[i].idx = i;
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i=0; i<v.size(); ++i){
            if(v[i].val != heights[i]) ++ans;
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