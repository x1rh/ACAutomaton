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

    int numPairsDivisibleBy60(vector<int>& time) {
        for(int i=0; i<time.size(); ++i){
            time[i] %= 60;
        }
        sort(time.begin(), time.end());
        int ans=0, cnt=0;
        for(int i=0; i<time.size()-1; ++i){
            auto it = lower_bound(time.begin()+i+1, time.end(), 60-time[i]);
            cnt = 0;
            while(it!=time.end() && *it==60-time[i]) {++cnt;++it;}
            ans += cnt;
        }
        for(cnt=0; cnt<time.size()&&time[cnt]==0; ++cnt);
        return ans+cnt*(cnt-1)/2;
    }
};

int main(){
    Solution sol;
    vector<int> v({60,60,60});
    cout<<sol.numPairsDivisibleBy60(v)<<endl;
    return 0;
}