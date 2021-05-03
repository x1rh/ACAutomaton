/*
记ra[i]表示第i个月兔子的数量，则：
ra[i] = ra[i-2]*2 + ra[i-1] - ra[i-2] = ra[i-1] + ra[i-2]

即斐波那契数列数列
*/



#include <iostream>
#include <vector>

using namespace std;

int main(){
    int month;
    
    while(cin>>month){
        vector<int> ra(month+1);
        ra[0] = 0;
        ra[1] = 1;
        ra[2] = 1;
        for(int i=3; i<=month; ++i){
            ra[i] = ra[i-1] + ra[i-2];
        }
        cout<<ra[month]<<endl;
    }
    
    return 0;
}