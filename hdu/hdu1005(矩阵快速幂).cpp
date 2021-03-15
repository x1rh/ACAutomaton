#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 7;

struct Matrix{
    int g[2][2];
    Matrix(){
        memset(g, 0, sizeof(g));
    }
    void output(){
        cout<<g[0][0]<<" "<<g[0][1]<<endl;
        cout<<g[1][0]<<" "<<g[1][1]<<endl;
    }
};

Matrix operator* (const Matrix &a, const Matrix &b){
    Matrix c;
    for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            for(int k=0; k<2; ++k){
                c.g[i][j] += (a.g[i][k] * b.g[k][j]) % MOD;
                c.g[i][j] %= MOD;
            }
        }
    }
    return c;
}

Matrix QuickPower(Matrix &base, int n){
    if(n==1){
        return base;
    }
    else{
        if(n&1){
            return base * QuickPower(base, n-1);
        }
        else{
            Matrix temp = QuickPower(base, n/2);
            return temp * temp;
        }
    }
}

int main(){
    int A, B, n;
    while(scanf("%d%d%d", &A, &B, &n)!= EOF){
        if(A==0 && B==0 && n==0) break;
        if(n==1 || n==2){
            cout<<1<<endl;
            continue;
        }
        Matrix base;
        base.g[0][0] = 0; base.g[0][1] = 1;
        base.g[1][0] = B; base.g[1][1] = A;
        Matrix ans = QuickPower(base, n-2);
        cout << (ans.g[1][0] + ans.g[1][1]) % MOD << endl;
     }
    return 0;
}