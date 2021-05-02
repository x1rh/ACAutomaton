/*
方法一：构造一把长度为m的尺子（m个奇数之和），尺子从m*m - m 开始移动到m*m + m即可获得答案
方法二：列式子解数列和方程
*/


#include <iostream>
#include <vector>

using namespace std;

int main(){
    int m;
    while(cin>>m){
        int ed = 0;
        if(m*m & 1){
            ed = m*m;
        }
        else{
            ed = m*m+1;
        }
        int st = ed - 2*(m-1);
        for(int i=st, j=ed; i<=ed; i+=2, j+=2){
            int ruler = (i+j)*m/2;
            if(ruler == m*m*m){
                for(int k=i; k<=j; k+=2){
                    if(k==i) cout<<k;
                    else cout<<"+"<<k;
                }
                cout<<endl;
            }
        }
       
    }
    
    return 0;
}