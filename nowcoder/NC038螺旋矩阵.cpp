/*
抽象成每次遍历一圈

注意处理特殊情况，如只有一行，或者只有一列
*/

class Solution {
public:
    void circle(int ii, int jj, int row, int col, vector<int> &ans, vector<vector<int> > &matrix){
        for(int i=0; i<col; ++i) ans.push_back(matrix[ii][jj++]);
        --jj;
        ++ii;
        if(ans.size() >= matrix.size()*matrix[0].size()) return ;
        for(int i=0; i<row-1; ++i) ans.push_back(matrix[ii++][jj]);
        --ii;
        --jj;
        if(ans.size() >= matrix.size()*matrix[0].size()) return ;
        for(int i=0; i<col-1; ++i) ans.push_back(matrix[ii][jj--]);
        --ii;
        ++jj;
        if(ans.size() >= matrix.size()*matrix[0].size()) return ;
        for(int i=0; i<row-2; ++i) ans.push_back(matrix[ii--][jj]);
        if(ans.size() >= matrix.size()*matrix[0].size()) return ;
    }
    
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int m = matrix.size();
        vector<int> ans;
        if(m == 0) return ans;
        int n = matrix[0].size();
        int ii=0, jj=0;
        while(ans.size() < m*n){
            circle(ii, jj, m-ii*2, n-ii*2, ans, matrix);
            ++ii;
            ++jj;
        }
        return ans;
    }
};