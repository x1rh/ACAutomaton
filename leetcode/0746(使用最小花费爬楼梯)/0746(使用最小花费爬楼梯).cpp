#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

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
    // 搜索
    // struct Node{
    //     int idx, cost;
    //     Node(){}
    //     Node(int idx, int cost):idx(idx), cost(cost){}
    // };
    // int g[1024];
    // int bfs(vector<int>& cost, int idx){
    //     int ans = 0x7f7f7f7f;
    //     memset(g, 0x7f, sizeof(g));
    //     queue<Node> q;
    //     g[idx] = cost[idx];
    //     q.emplace(idx, cost[idx]);
    //     while(!q.empty()){
    //         Node temp = q.front();
    //         q.pop();
    //         int idx1 = temp.idx + 1;
    //         int idx2 = temp.idx + 2;

    //         if(idx1>=cost.size() || idx2>=cost.size()){
    //             if(temp.cost < ans){
    //                 ans = temp.cost;
    //             }
    //             continue;
    //         }

    //         int cost1 = temp.cost + cost[idx1];
    //         int cost2 = temp.cost + cost[idx2];

    //         if(idx1<cost.size() && g[idx1] > cost1){
    //             g[idx1] = cost1;
    //             q.emplace(idx1, cost1);
    //         }
    //         if(idx2<cost.size() && g[idx2] > cost2){
    //             g[idx2] = cost2;
    //             q.emplace(idx2, cost2);
    //         }
    //     }
    //     return ans;
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     return min(bfs(cost, 0), bfs(cost, 1));
    // }
    int minCostClimbingStairs(vector<int>& cost){
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<cost.size(); ++i){
            dp[i] = min(dp[i-1]+cost[i], dp[i-2]+cost[i]);
        }
        if(cost.size() <= 1){
            return 0;
        }
        else return min(dp[cost.size()-1], dp[cost.size()-2]);
    }
};

int main(){
    Solution sol;
    vector<int> v({1, 100, 1, 1, 1, 100, 1, 1, 100, 1});
    cout<<sol.minCostClimbingStairs(v)<<endl;
    return 0;
}