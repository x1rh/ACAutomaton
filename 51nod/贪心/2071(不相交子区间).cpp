#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int st, ed;
    Node(){}
    bool operator<(const Node& rhs)const{
        if(st<rhs.st) return true;
        else if(st==rhs.st) return ed > rhs.ed;
        else return false;
    }
};

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        vector<Node> inp(n), arr;
        for(int i=0; i<n; ++i){
            scanf("%d%d", &inp[i].st, &inp[i].ed);

        }
        sort(inp.begin(), inp.end());

        int ii=0, jj=0;
        for(; ii<n;){
            for(jj=ii+1; jj<n&&inp[jj].st==inp[ii].st; ++jj);
            arr.push_back(inp[jj-1]);
            ii = jj;
            if(jj>=n) break;
        }
    }
    return 0;
}