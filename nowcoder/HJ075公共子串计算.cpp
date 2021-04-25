#include <bits/stdc++.h>

using namespace std;

int main(){
    string A, B;
    
    while(cin>>A>>B){
        int ans = 1;
        vector<vector<int>> dp(A.size(), vector<int>(B.size()));
        for(int i=0; i<A.size(); ++i){
            if(A[i] == B[0]) dp[i][0] = 1;
        }
        for(int i=0; i<B.size(); ++i){
            if(B[i] == A[0]) dp[0][i] = 1;
        }
        
        
        for(int i=1; i<A.size(); ++i){
            for(int j=1; j<B.size(); ++j){
                if(A[i] == B[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    if(dp[i][j] > ans) ans = dp[i][j];
                }
                else{
                    dp[i][j] = 0;
                }
                
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}