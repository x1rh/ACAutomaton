/*
直接递推。需要仔细参考输入样例，走法为沿着方格的边走，逻辑上n与m都加一抽象为沿着空格走即可

*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    while(cin>>n>>m){
        ++n; 
        ++m;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][1] = 1;
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        cout<<dp[m][n]<<endl;
    }
    
    return 0;
}