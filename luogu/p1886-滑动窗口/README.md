拿最小值来举例：  
- x加入到滑动窗口中，则当前窗口中所有大于x的值都失去了意义，因为x比这些值更小且更晚离开滑动窗口（既生瑜何生亮，雾），这些值在x出现后就不可能是当前窗口的最小值，直接抛弃即可。  
- 需要注意维护窗口内的值的合法性，过期的值需要抛弃。 
- 具体实现，用cpp优先队列维护一个单调不减的单调队列，每次移动滑动窗口时，将队列头中过期的（已经不在滑动窗口中的值）、大于x的值全部删除即可。


最大值同理，维护一个单调不增的单调队列。  

 

使用优先队列实现单调队列非常方便，贡献一个非常简洁直观的写法。  
```cpp
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

```