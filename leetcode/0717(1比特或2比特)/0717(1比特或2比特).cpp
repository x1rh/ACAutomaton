#include <iostream>
#include <vector>

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
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        int i=0, j=0;
        while(i<len){
            if(bits[i]==0){
                j = i;
                ++i;
            }
            else{
                i = i+2;
            }
        }
        if(i==j+1) return true;
        else return false;
    }
};

int main(){
    Solution sol;
    vector<int> v({});
    cout<<sol.isOneBitCharacter(v)<<endl;
    return 0;
}