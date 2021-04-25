#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> pn;
    for(int i=2; i<=500000; ++i){
        int sum = 0;
        for(int j=1; j*j<=i; ++j){
            if(i%j==0){
                if(j==1) sum += 1;
                else{
                    sum += j;
                    sum += i/j;
                }
            }
        }
        if(sum == i) pn.push_back(i);
    }
    int n;
    while(cin>>n){
        int idx = lower_bound(pn.begin(), pn.end(), n) - pn.begin();
        if(idx<pn.size()){
            if(pn[idx]==n){
                cout<<idx+1<<endl;
            }
            else{
                cout<<idx<<endl;
            }
        }
        else{
            cout<<pn.size()<<endl;
        }
    }
    
    return 0;
}