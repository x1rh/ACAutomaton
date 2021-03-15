#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
char A[MAXN], B[MAXN], ans[MAXN];
int C[MAXN];

int main(){
    int T;
    scanf("%d", &T);
    for (int kase = 0; kase < T; ++kase)
    {
        memset(A, 0, sizeof(char)*MAXN);
        memset(B, 0, sizeof(char)*MAXN);
        memset(C, 0, sizeof(int) * MAXN);
        memset(ans, 0, sizeof(char)*MAXN);
        scanf("%s%s", &A, &B);
        int L1 = strlen(A);
        int L2 = strlen(B);
        int idx = 0;

        int carry = 0;
        while(L1 && L2){
            C[idx++] = (carry + ((int)(A[L1-1] + B[L2-1] - '0' - '0'))) % 10;
            carry = (carry + ((int)(A[L1-1] + B[L2-1] - '0' - '0'))) / 10;
            --L1;
            --L2;
        }


        while(L1){
            C[idx++] = (carry + ((int)(A[L1-1] - '0'))) % 10;
            carry = (carry + ((int)(A[L1-1] - '0'))) / 10;
            --L1;
        }


        while(L2){
            C[idx++] = (carry + ((int)(B[L2 - 1] - '0'))) % 10;
            carry = (carry + ((int)(B[L2 - 1] - '0'))) / 10;
            --L2;
        }

        if(carry){
            C[idx++] = carry;
        }

        bool flag = false;
        int lrh = 0;
        for (int i = 0; i<=idx; ++i){
            if(!flag && C[idx-i]==0){
                continue;
            }
            else{
                flag = true;
            }
            ans[lrh++] = ((char)C[idx - i] + '0');
        }

        ans[lrh] = '\0';

        if (kase)
            printf("\n");
        printf("Case %d:\n", kase+1);
        printf("%s + %s = %s\n", A, B, ans);
    }
    return 0;
}


