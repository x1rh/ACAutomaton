/*
设待求的两个数为a和b，则：
a * b = lcm(a, b) * gcd(a, b)

*/

#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
    return b?gcd(b, a%b):a;
}

int main(){
    long long a, b;
    while(cin>>a>>b){
        cout<<a*b/gcd(a,b)<<endl;
    }
}