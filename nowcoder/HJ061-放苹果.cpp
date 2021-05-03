/*
对盘子暴搜
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

map<string, bool> mp;

void make_string(vector<int> plv){
    sort(plv.begin(), plv.end());
    string s("");
    for(auto el:plv){
        stringstream ss;
        ss<<el;
        s += ss.str();
    }
    if(!mp[s]) mp[s] = true;
}

void dfs(vector<int> &plv, int pl, int app){
    if(pl == plv.size()){
        if(app!=0) return;
        make_string(plv);
    }
    else{
        for(int i=0; i<=app; ++i){
            plv[pl] = i;
            dfs(plv, pl+1, app-i);
        }
    }
}

int main(){
    int pl, app;
    while(cin>>app>>pl){
        vector<int> plv(pl, 0);
        mp.clear();
        dfs(plv, 0, app);
        cout<<mp.size()<<endl;
    }
    return 0;
}