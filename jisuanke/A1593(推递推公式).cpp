#include <iostream>
#include <iomanip>

using namespace std;

const int MAXN = 1024;
double C[MAXN];


int main(){
    int n;
    double a0, an1, presum;
    while(cin>>n){
        cin>>a0>>an1;
        presum = 0;
        for(int i=0; i<n; ++i){
            cin>>C[i];
            presum += (n-i)*C[i];
        }

        double ans = (n*a0 + an1 - 2*presum) / (n+1);
        cout<< fixed << setprecision(2) << ans <<endl;

    }
    return 0;
}