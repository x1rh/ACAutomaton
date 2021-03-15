#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        vector<int> arr(n);
        for(int i=0; i<n; ++i) scanf("%d", &arr[i]);
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i=0; i<arr.size(); ++i){
            ans += arr[i] * (arr.size()-i);
        }
        printf("%d\n", ans);
    }
    return 0;
}