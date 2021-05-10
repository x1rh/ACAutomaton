#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
        int x, idx;
        Node(){}
        Node(int x, int idx):x(x), idx(idx){}
        bool operator<(const Node& rhs){
            return x<rhs.x;
        }
    };

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<Node> v;
        for(int i=0; i<nums.size(); ++i){
            v.emplace_back(nums[i], i);
        }
        sort(v.begin(), v.end());
        for(int i=1; i<v.size(); ++i){
            if(v[i-1].x==v[i].x && abs(v[i-1].idx-v[i].idx)<=k){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> v({1,2,3,1,2,3});
    cout<<sol.containsNearbyDuplicate(v, 2)<<endl;
    return 0;
}