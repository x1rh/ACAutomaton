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
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> mp;
        for(int i=0; i<deck.size(); ++i){
            mp[deck[i]] += 1;
        }

        int gcd = -1;

        for(auto it=mp.begin(); it!=mp.end(); ++it){
            if(gcd == -1){
                gcd = it->second;
            }
            else{
                gcd = __gcd(gcd, it->second);
            }
        }
        if(mp.size()==1 && mp.begin()->second>=2) return true;
        else if(gcd >= 2) return true;
        else return false;
    }
};

int main(){
    Solution sol;
    vector<int> v({1,2,3,4,4,3,2,1});
    cout<<sol.hasGroupsSizeX(v)<<endl;
    return 0;
}