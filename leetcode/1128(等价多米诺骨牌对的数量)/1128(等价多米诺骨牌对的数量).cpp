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
        int first, second;
        Node(){}
        Node(int first, int second):first(first), second(second){}
        bool operator<(const Node& rhs)const{
            if(first < rhs.first) return true;
            else if(first == rhs.first) return second < rhs.second;
            else return false;
        }
    };
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<Node, int> mp;
        Node temp;
        int ans = 0;
        for(int i=0; i<dominoes.size(); ++i){
            if(dominoes[i][0] > dominoes[i][1]){
                temp.first = dominoes[i][1];
                temp.second = dominoes[i][0];
            }
            else{
                temp.first = dominoes[i][0];
                temp.second = dominoes[i][1];
            }
            ++mp[temp];
        }

        for(auto it=mp.begin(); it!=mp.end(); ++it){
            ans += (it->second-1)*it->second/2;
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> v({{1,2},{2,1},{3,4},{5,6}});
    cout<<sol.numEquivDominoPairs(v)<<endl;
    return 0;
}