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

    struct Node{
        int to, di;
        Node(){}
        Node(int to, int di):to(to), di(di){}
        bool operator<(const Node& rhs)const{
            return di<rhs.di;
        }
    };
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sz = distance.size();
        vector<vector<Node>> g(sz);
        for(int i=0; i<sz; ++i){
            g[i].emplace_back((i+1)%sz, distance[i]);
            g[(i+1)%sz].emplace_back(i, distance[i]);
        }
        queue<Node> q;
        vector<int> dist(sz, numeric_limits<int>::max() );
        dist[start] = 0;
        q.emplace(start, 0);
        while(!q.empty()){
            Node fr = q.front();
            q.pop();
            for(int i=0; i<g[fr.to].size(); ++i){
                int to = g[fr.to][i].to;
                int cost = g[fr.to][i].di;
                if(dist[to] > fr.di+cost){
                   dist[to] = fr.di+cost;
                   q.emplace(to, dist[to]);
                }
            }
        }
        return dist[destination];
    }
};

int main(){
    Solution sol;
    vector<int> dis({1, 2, 3, 4});
    cout<<sol.distanceBetweenBusStops(dis, 0, 3)<<endl;
    return 0;
}