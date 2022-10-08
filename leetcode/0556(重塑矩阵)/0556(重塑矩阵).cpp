class Solution {
public:

    void nxt(int &dx, int &dy, int rc){
        ++dy;
        if(dy>=rc){
            dy = 0;
            ++dx;
        }
    };

    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int rr = mat.size();
        if(rr==0){
            if(r*c==0) return vector<vector<int>>();
            else return mat;
        }
        int rc = mat[0].size();
        if(rr*rc == r*c){
            

            vector<vector<int>> ans(r, vector<int>(c, 0));
            int cx=0, cy=0;
            for(int i=0; i<r; ++i){    
                for(int j=0; j<c; ++j){
                    ans[i][j] = mat[cx][cy];
                    nxt(cx, cy, rc);

                }
            }
            return ans;
        }
        else{
            return mat;
        }
    }
};