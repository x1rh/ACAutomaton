#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

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
    int minCostToMoveChips(vector<int>& chips) {
        int sz = chips.size();
        map<int, int> mp;

        for(int i=0; i<sz; ++i){
            ++mp[chips[i]];
        }

        int ii=0, jj, ans=numeric_limits<int>::max();
        for(auto it=mp.begin(); it!=mp.end(); ++it, ++ii){
            auto jt = it;
            --jt;
            jj = ii - 1;
            int tmp=0, dist;
            while(jj>=0){
                dist = it->first - jt->first;
                if(dist & 1){
                    tmp += jt->second;
                }
                --jj;
                --jt;
            }
            jt = it;
            ++jt;
            while(jt!=mp.end()){
               dist = jt->first - it->first;
               if(dist & 1){
                   tmp += jt->second;
               }
               ++jt;
            }
            ans = min(tmp, ans);
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> v({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30});
    cout<<sol.minCostToMoveChips(v)<<endl;
    return 0;
}