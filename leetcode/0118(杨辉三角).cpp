#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0; i<numRows; ++i){
            vector<int> temp;
            for(int j=0; j<=i; ++j){
                if(j==0 || j==i){
                    temp.push_back(1);
                }
                else if(j!=i){
                    temp.push_back(res[i-1][j]+res[i-1][j-1]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> v = sol.generate(5);
    for(int i=0; i<v.size(); ++i){
        for(int j=0; j<v[i].size(); ++j){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}