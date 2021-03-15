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
        int val, idx, rnk;
        Node(){}
        Node(int val, int idx, int rnk):val(val), idx(idx), rnk(rnk){}
        bool operator<(const Node& rhs)const{
            return val < rhs.val;
        }
    };
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<Node> v(arr.size());
        vector<int> ans(arr.size());
        if(arr.size()==0) return ans;
        for(int i=0; i<arr.size(); ++i){
            v[i].val = arr[i];
            v[i].idx = i;
        }
        sort(v.begin(), v.end());

        int ord = 1;
        v[0].rnk = ord;
        for(int i=1; i<v.size(); ++i){
            if(v[i].val == v[i-1].val){
                v[i].rnk = ord;
            }
            else{
                v[i].rnk = ++ord;
            }
        }

        for(int i=0; i<v.size(); ++i){
            ans[v[i].idx] = v[i].rnk;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> arr({1});
    vector<int> ans = sol.arrayRankTransform(arr);
    print(ans);
    return 0;
}