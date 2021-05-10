#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

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
    int maxDistToClosest(vector<int>& seats) {
        int sz = seats.size();
        int st=0, ed=sz-1;
        int max_len = 0;

        for(; st<sz&&seats[st]==0; ++st);
        for(; ed>=0&&seats[ed]==0; --ed);

        int i=st, j;
        int len = max(st, sz-ed-1);

        while(i<sz){
            while(i<sz && seats[i]!=0) ++i;
            j = i;
            while(j<sz && seats[j]==0) ++j;
            if(j-i > max_len){
                max_len = j-i;
            }
            i = j;
        }
        if(max_len&1){
            return max((max_len+1)/2, len);
        }
        else{
            return max(max_len/2, len);
        }
    }
};

int main(){
    Solution sol;
    vector<int> v({1,0,0,0});
    cout<<sol.maxDistToClosest(v)<<endl;
    return 0;
}