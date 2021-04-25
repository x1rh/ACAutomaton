/*
按要求模拟即可
*/

#include <bits/stdc++.h>

using namespace std;


int main(){
    int m, n, x1, y1, x2, y2, x, y;
    while(cin>>m>>n){
        if(m<=9 && n<=9) cout<<0<<endl;
        else cout<<-1<<endl;
        
        cin>>x1>>y1>>x2>>y2;
        if(0<=x1 && x1<m && 0<=y1 && y1<n && 0<=x2 && x2<m && 0<=y2 && y2<n) 
            cout<<0<<endl;
        else 
            cout<<-1<<endl;
        
        cin>>x;
        if(m+1<=9 && 0<=x && x<m) {
            cout<<0<<endl;
        }
        else cout<<-1<<endl;
        
        cin>>y;
        if(n+1<=9 && 0<=y && y<n) {
            cout<<0<<endl;
        }
        else cout<<-1<<endl;
        
        cin>>x>>y;
        if(0<=x && x<m && 0<=y && y<n) cout<<0<<endl;
        else cout<<-1<<endl;
       
        
    }    
    
    return 0;
}