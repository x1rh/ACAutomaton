#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

double mod360(double x){
    int deg = (int)x;
    int mul = x / 360;
    return x - mul * 360;
}

int main(){
    double D;
    double vs = 6;
    double vm = 0.1;
    double vh = 1.0/240.0;

    int total = 24*60*60;
    while(cin>>D){
        if(D==-1) break;
        else{
            if(D>=120){
                cout<<"0.000"<<endl;
            }
            else if(D==0){
                cout<<"100.000"<<endl;
            }
            else{
                int cnt = 0;
                for(int i=0; i<total; ++i){
                    double ds = mod360(vs*i);
                    double dm = mod360(vm*i);
                    double dh = mod360(vh*i);
                    if(fabs(ds-dm) >= D && fabs(ds-dh) >= D && fabs(dh-dm) >= D){
                        ++cnt;
                    }
                }
                cout<< cnt <<endl;
                cout<< cnt * 1.0 / total*1.0 * 100<<endl;
            }
        }
    }
    return 0;
}