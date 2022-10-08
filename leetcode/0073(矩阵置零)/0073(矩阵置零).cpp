class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int zi=-1, zj=-1;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[i].size(); ++j){
                if(matrix[i][j] == 0){
                    zi = i;
                    zj = j;
                    break;
                }
            }
            if(zi!=-1) break;
        }

        zj = -1;
        if(zi==-1 && zj==-1) return;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[i].size(); ++j){
                if(matrix[i][j] == 0){
                    for(int k=0; k<matrix[i].size(); ++k){
                        if(matrix[i][k]==0){
                            bool flag = false;
                            for(int g=0; g<=zj; ++g){
                                if(matrix[zi][g]==k){
                                    flag = true;
                                    break;
                                }
                            }
                            if(!flag) matrix[zi][++zj] = k;
                        }
                        if(zi!=i) matrix[i][k] = 0;
                    }
                    
                    break;
                }
            }
        }


        for(int i=0; i<=zj; ++i){
            for(int j=0; j<matrix.size(); ++j){
                if(j == zi) continue;
                matrix[j][ matrix[zi][i] ] = 0;
            }
        }

        for(int i=0; i<matrix[0].size(); ++i){
            matrix[zi][i] = 0;
        }
    }
};