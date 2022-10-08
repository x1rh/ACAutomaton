class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1; i<numRows; ++i){
            int one=0, two=0;
            vector<int> tmp;
            int sz = ans[i-1].size();
            for(int j=-1; j<sz; ++j){
                if(j==-1) one = 0;
                else one = ans[i-1][j];
                if(j+1==ans[i-1].size()) two = 0;
                else two = ans[i-1][j+1];
                tmp.push_back(one + two);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};