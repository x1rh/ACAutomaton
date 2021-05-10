#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void print(const vector<T>& v){
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
    void reverse(vector<int>& v, int l, int r){
        while(l<r){
            swap(v[l++], v[r--]);
        }
    }

    void rotate(vector<int>& nums, int k){
        if(nums.size()<=1) return;
        k %= nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
};

int main(){
    Solution sol;
    vector<int> v({1,2,3,4,5,6,7});
    sol.rotate(v, 3);
    print(v);
    return 0;
}