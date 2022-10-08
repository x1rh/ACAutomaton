class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> f(n+1, vector<double>(target+1, 0));
        f[0][0] = 1.0;

        for(int i=1; i<=n; i++) {
            for(int j=0; j<=i && j <=target; j++) {
                if(j >= 1) {
                    f[i][j] = f[i-1][j] * (1 - prob[i-1]) + f[i-1][j-1] * prob[i-1];
                } else {
                    f[i][j] = f[i-1][j] * (1 - prob[i-1]);
                }
            }
        }
        return f[n][target];
    }
};