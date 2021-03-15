#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 10;
int A[MAXN];

int main(){
    int kase, n;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        for (int i = 0; i < n; ++i){
            scanf("%d", &A[i]);
        }
    }
    return 0;
}