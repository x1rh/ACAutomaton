#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       for(int i=m; i<m+n; ++i){
           nums1[i] = nums2[i-m];
       }
       sort(nums1.begin(), nums1.begin()+m+n);
    }
};

int main(){
    vector<int> v1({1,2,3,0,0,0});
    vector<int> v2({2,5,6});
    Solution sol;
    sol.merge(v1, 3, v2, 3);
    for(int i=0; i<v1.size(); ++i){
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    return 0;
}