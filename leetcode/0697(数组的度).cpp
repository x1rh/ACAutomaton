#include <iostream>
#include <vector>
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
    // struct Node{
    //     int frm, to, val;
    //     Node(){}
    //     Node(int frm, int to, int val):frm(frm), to(to), val(val){}
    // };

    int findShortestSubArray(vector<int>& nums) {
        int deg = 0;
        vector<int> mp(50000, 0);
        for(auto i=0; i<nums.size(); ++i){
            mp[nums[i]] += 1;
            if(mp[nums[i]] > deg) deg = mp[nums[i]];
        }
        map<int, pair<int, int> > r;
        for(int i=0; i<50000; ++i){
            if(mp[i] == deg){
                r[i] = make_pair(-1, -1);
            }
        }
        for(auto i=0; i<nums.size(); ++i){
            if(mp[nums[i]] == deg){
                if(r[nums[i]].first == -1){
                    r[nums[i]].first = i;
                    r[nums[i]].second = i;
                }
                else{
                    r[nums[i]].second = i;
                }
            }
        }
        int ans = 50001;
        for(auto it=r.begin(); it!=r.end(); ++it){
            cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
            int frm = it->second.first;
            int to = it->second.second;
            int di = to - frm + 1;
            if(di < ans) ans = di;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> v{1};
    cout<<sol.findShortestSubArray(v)<<endl;
    return 0;
}