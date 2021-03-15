#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n==0)
            break;
        map<string, int> mp;
        string ss, ans;
        int max_cnt = -1;
        for (int i = 0; i < n; ++i){
            cin >> ss;
            mp[ss] += 1;
            if(max_cnt < mp[ss]){
                max_cnt = mp[ss];
                ans = ss;
            }
        }
        cout << ans << endl;
    }
    return 0;
}