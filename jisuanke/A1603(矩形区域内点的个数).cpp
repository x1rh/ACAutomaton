#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 2000+5;

int dp[MAXN][MAXN];

int main(){
    int n, q, x, y, v, x1, y1, x2, y2;
    while(scanf("%d", &n) != EOF){

        memset(dp, 0, sizeof(dp));

        for(int i=0; i<n; ++i){
            scanf("%d%d%d", &x, &y, &v);
            dp[x+1][y+1] += v;
        }

        for(int i=1; i<2002; ++i){
            for(int j=1; j<2002; ++j){
                dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }

        scanf("%d", &q);
        while(q--){
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            ++x1, ++y1, ++x2, ++y2;
            printf("%d\n", dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]);
        }

    }
    return 0;
}