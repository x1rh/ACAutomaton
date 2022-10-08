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
    struct Node{
        int x, y;
        Node(){}
        Node(int x, int y):x(x), y(y){}
        bool operator<(const Node& rhs)const{
            if(x<rhs.x) return true;
            else if(x==rhs.x) return y<rhs.y;
            else return false;
        }
    };
    const double EXP = 0.000000001;
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2) return true;
        vector<Node> v(coordinates.size());
        for(int i=0; i<coordinates.size(); ++i){
            v[i].x = coordinates[i][0];
            v[i].y = coordinates[i][1];
        }
        sort(v.begin(), v.end());
        bool f = false;
        for(int i=1; i<coordinates.size()-1; ++i){
            int pre_x = v[i].x - v[i-1].x;
            int pre_y = v[i].y - v[i-1].y;

            int aft_x = v[i+1].x - v[i].x;
            int aft_y = v[i+1].y - v[i].y;

            if(pre_x==0 && aft_x!=0){
                return false;
            }
            else if(pre_x==0 && aft_x==0){
                continue;
            }
            else{
                double one = double(pre_y) / double(pre_x);
                double two = double(aft_y) / double(aft_x);
                if(fabs(one - two) > EXP){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution sol;

    return 0;
}