#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 10;
const long long MOD = 1e9 + 7;

struct Point{
    long long x, y;
    Point(){}
    Point(long long x, long long y):x(x), y(y){}
};

Point arr[MAXN];

bool cmp(const Point &lva, const Point &rva){
    if(lva.x < rva.x) return true;
    else if(lva.x == rva.x){
        return lva.y < rva.y;
    }
    else return false;
}

long long dist(const Point &frm, const Point &to){

    long long t1 = (to.x - frm.x)%MOD;
    long long t2 = (to.y - frm.y)%MOD;
    return ((t1*t1)%MOD + (t2*t2)%MOD)%MOD;
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        for(int i=0; i<n; ++i){
            scanf("%lld%lld", &arr[i].x, &arr[i].y);
        }

        sort(arr, arr+n, cmp);

        Point O(0, 0);

        long long ans = 0;
        for(int i=0; i<n; ++i){
            ans = (ans + dist(O, arr[i]))%MOD;
            O = arr[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}