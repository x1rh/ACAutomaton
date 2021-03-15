#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <cmath>

using namespace std;

template <typename T>
void print(vector<T>& v){
    for(auto it=v.begin(); it!=v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

template<typename T>
void print(vector<vector<T>>& v){
    for(auto iti=v.begin(); iti!=v.end(); ++iti){
        for(auto itj=(*iti).begin(); itj!=(*iti).end(); ++itj){
            cout<<*itj<<" ";
        }
        cout<<endl;
    }
}

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int one, two;
        for(int i=1; i<points.size(); ++i){
            if(points[i][0] == points[i-1][0]){
                ans += abs(points[i][1] - points[i-1][1]);
            }
            else if(points[i][1] == points[i-1][1]){
                ans += abs(points[i][0] - points[i-1][0]);
            }
            else{
                one = abs(points[i][0] - points[i-1][0]);
                two = abs(points[i][1] - points[i-1][1]);
                ans += max(one, two);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid({{1,2,3},{4,5,6},{7,8,9}});
    sol.shiftGrid(grid, 1);
    print(grid);
    return 0;
}