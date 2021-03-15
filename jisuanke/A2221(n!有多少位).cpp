#include <iostream>
#include <cmath>

using namespace std;

double cal(int n){
    double res = 0;
    for(int i=1; i<=n; ++i){
        res += log10(i);
    }
    return res+1;
}

int digit_stirling(int n)
{
    double PI=acos(double(-1));// PI的值=反余弦函数 -1.0为Pi， 1为0。
    double e=exp(double(1));//e的值
    return floor(log10(sqrt(2*PI*n))+n*log10(n/e))+1;
}


int main(){
    for(int i=1; i<=10000; ++i){
        if(cal(i) >= 10000){
            cout<<"i is: "<<i<<endl;
            break;
        }
    }
    return 0;
}