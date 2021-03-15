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
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> vk;
        vector<int> ans;
        while(K){
            vk.push_back(K%10);
            K /= 10;
        }
        reverse(A.begin(), A.end());
        int i=0, j=0, digit, carry=0;
        while(i<A.size() && j<vk.size()){
            digit = (carry+A[i]+vk[j])%10;
            carry = (carry+A[i]+vk[j])/10;
            ans.push_back(digit);
            ++i;
            ++j;
        }
        if(i==A.size() && j==vk.size() && carry){
            ans.push_back(carry);
        }
        else if(i<A.size()){
             while(i<A.size()){
                digit = (carry+A[i])%10;
                carry = (carry+A[i])/10;
                ans.push_back(digit);
                ++i;
            }
            if(carry) {
                ans.push_back(carry);
            }
        }
        else if(j<vk.size()){
            while(j<vk.size()){
                digit = (carry+vk[j])%10;
                carry = (carry+vk[j])/10;
                ans.push_back(digit);
                ++j;
            }
            if(carry) ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> v({6});
    vector<int> ans = sol.addToArrayForm(v, 809);
    print(ans);

    return 0;
}