#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        int ans = 0;
        while(n){
            ans += n/5;
            n /= 5;
        }
    }
    return 0;
}