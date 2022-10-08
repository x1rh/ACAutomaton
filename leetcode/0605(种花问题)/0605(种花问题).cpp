#include <iostream>
#include <vector>
#include <algorithm>

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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        if(len==0) return 0;
        bool f1, f2;
        int i=0, j=0, cnt=0;
        for(int i=0; i<len; ++i){
            if(flowerbed[i]==0){
                if((i>=1&&flowerbed[i-1]==0) || i==0) {
                    f1 = true;
                }
                else{
                    f1 = false;
                }
                if(((i<len-1)&&flowerbed[i+1]==0) || i==len-1) {
                    f2 = true;
                }
                else{
                    f2 = false;
                }
                if(f1 && f2) {
                    ++cnt;
                    flowerbed[i] = 1;
                }
            }
        }
        return cnt >= n;
    }
};

int main(){
    Solution sol;
    vector<int> v({1,0,0,0,0,1});
    cout<<sol.canPlaceFlowers(v, 2)<<endl;

    return 0;
}