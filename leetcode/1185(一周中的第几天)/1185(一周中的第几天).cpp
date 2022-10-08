#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <list>

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
    bool judge(int year){
        return (year%4==0&&year%100!=0) || year%400==0;
    }

    // string dayOfTheWeek(int day, int month, int year) {
    //     vector<string> v({"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"});
    //     vector<int> mm({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
    //     int y = 1970;
    //     int m = 1;
    //     int d = 1;
    //     int now = 4;

    //     int delta = 0;
    //     for(int i=y; i<year; ++i){
    //         if(judge(i)){
    //             delta += 366;
    //         }
    //         else{
    //             delta += 365;
    //         }
    //     }

    //     for(int i=1; i<month; ++i){
    //         delta += mm[i-1];
    //     }
    //     delta += day;
    //     if(judge(year) && month>2) ++delta;
    //     return v[(now + delta - 1)%7];
    // }

    string dayOfTheWeek(int day, int month, int year) {
        vector<string> v({"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"});
        if(month<3){
            --year;
            month += 12;
        }
        int c = year / 100;
        int y = year - c*100;
        int w = (c/4-2*c+y+y/4+13*(month+1)/5+day-1)%7;
        cout<<w<<endl;
        return v[(w+7)%7];
    }


};

int main(){
    Solution sol;
    cout<<sol.dayOfTheWeek(7, 3, 2003)<<endl;
    return 0;
}