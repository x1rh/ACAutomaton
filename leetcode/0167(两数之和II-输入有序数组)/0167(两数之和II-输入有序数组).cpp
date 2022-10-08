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

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int i=0; i<numbers.size(); ++i){
            auto it = lower_bound(numbers.begin()+i+1, numbers.end(), target-numbers[i]);
            if(it!=numbers.end() && *it==target-numbers[i]){
                res.push_back(i+1);
                res.push_back(distance(numbers.begin()+i+1, it)+i+2);
                break;
            }
        }
        return res;
    }
};

int main(){

    Solution sol;
    vector<int> v({2, 7, 11, 15});
    vector<int> res = sol.twoSum(v, 9);
    print(res);


    return 0;
}