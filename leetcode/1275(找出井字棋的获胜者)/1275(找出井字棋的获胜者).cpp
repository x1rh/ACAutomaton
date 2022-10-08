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
    char judge(vector<vector<char>>& g){
        int f1 = 0;
        int f2 = 0;
        for(int i=0; i<3; ++i){
            f1 = 0;
            f2 = 0;
            for(int j=0; j<3; ++j){
                if(g[i][j]=='A') ++f1;
                if(g[i][j]=='B') ++f2;
            }
            if(f1==3) return 'A';
            if(f2==3) return 'B';
        }

        for(int i=0; i<3; ++i){
            f1 = 0;
            f2 = 0;
            for(int j=0; j<3; ++j){
                if(g[j][i]=='A') ++f1;
                if(g[j][i]=='B') ++f2;
            }
            if(f1==3) return 'A';
            if(f2==3) return 'B';
        }

        f1 = 0;
        f2 = 0;
        for(int i=0; i<3; ++i){
            if(g[i][i]=='A') ++f1;
            if(g[i][i]=='B') ++f2;
        }
        if(f1==3) return 'A';
        if(f2==3) return 'B';

        f1 = 0;
        f2 = 0;
        for(int i=0; i<3; ++i){
            if(g[i][3-i-1]=='A') ++f1;
            if(g[i][3-i-1]=='B') ++f2;
        }
        if(f1==3) return 'A';
        if(f2==3) return 'B';
        return 'P';
    }

    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> g(3);
        char now;
        for(int i=0; i<3; ++i) g[i].resize(3);
        for(int i=0; i<moves.size(); ++i){
            if(i&1) now='B';
            else now='A';
            g[moves[i][0]][moves[i][1]] = now;
            char res = judge(g);
            if(res=='A') {
                return "A";
            }
            else if(res == 'B') {
                return "B";
            }
        }
        if(moves.size()>=9) return "Draw";
        else return "Pending";
    }
};

int main(){
    Solution sol;

    vector<vector<int>> moves({{0,0},{1,1}});
    cout<<sol.tictactoe(moves)<<endl;
    return 0;
}