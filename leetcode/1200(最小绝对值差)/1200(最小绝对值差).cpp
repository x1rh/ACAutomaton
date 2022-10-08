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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int delta = numeric_limits<int>::max(), temp;
        for(int i=1; i<arr.size(); ++i){
            temp = arr[i]-arr[i-1];
            if(delta > temp) delta = temp;
        }
        vector<vector<int>> ans;
        for(int i=1; i<arr.size(); ++i){
            if(arr[i]-arr[i-1] == delta){
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    return 0;
}