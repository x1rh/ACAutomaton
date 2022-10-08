#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace  std;

struct node {
    int x, i;
    node(int x, int i):x(x), i(i){}
    bool operator<(const node& rhs) const {
        return this->x < rhs.x;
    }
    bool operator>(const node& rhs) const {
        return this->x > rhs.x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    int m, n, x;
    cin>>m>>n;
    priority_queue<node> max;
    priority_queue<node, vector<node>, greater<node>> min;
    vector<int> a, b;
    for(int i=0; i<m; i++) {
        cin>>x;
        while(!min.empty() && (min.top().i <= i-n || min.top().x > x)) {
            min.pop();
        }
        min.push(node(x, i));

        while(!max.empty() && (max.top().i <= i-n || max.top().x < x)) {
            max.pop();
        }
        max.push(node(x, i));

        if(i >= n-1) {
            a.push_back(min.top().x);
            b.push_back(max.top().x);
        }
    }

    auto print = [](vector<int>& out) {
        for(int i=0; i<out.size(); i++) {
            if(i) {
                cout<<" ";
            }
            cout<<out[i];
        }
        cout<<endl;
    };

    print(a);
    print(b);
}