#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /* digits可能位数很长
    vector<int> plusOne(vector<int>& digits) {
        long long val = 0;
        for(size_t i=0; i<digits.size(); ++i){
            val = val*10 + digits[i];
        }
        ++val;
        vector<int> res;
        while(val){
            res.push_back(val%10);
            val /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    */
   vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int now;
        vector<int> res;
        ++digits[digits.size()-1];
        for(int i=digits.size()-1; i>=0; --i){
            now = (digits[i]+carry) % 10;
            carry = (digits[i]+carry) / 10;
            res.push_back(now);
        }
        if(carry) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    vector<int> v({4,3,2,1});
    Solution sol;
    vector<int> t = sol.plusOne(v);
    for(size_t i=0; i<t.size(); ++i){
        cout<<t[i]<<" ";
    }
    cout<<endl;
}