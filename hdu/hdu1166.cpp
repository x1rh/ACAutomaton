#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct BIT{
    int n;
    vector<int> tree;
    BIT(int n):n(n+1), tree(vector<int>(n+1)){}
    
    void build(vector<int>& arr){
        for(int i=0; i<this->n; i++) {
            update(i+1, arr[i]);
        }
    }

    void update(int index, int x) {
        for(int i=index; i<=this->n; i+=(i & (-i))){
            tree[i] += x;
        }
    }

    int query(int index) {
        int res = 0;
        for(int i=index; i>0; i-=(i & (-i))) {
            res += tree[i];
        }
        return res;
    }
};


int main() {
    int T, N, a, b;
    cin>>T;
    for(int kase=0; kase<T; kase++) {
        cout<<"Case "<<kase+1<<":"<<endl;
        cin>>N;
        vector<int> arr(N);
        for(int i=0; i<N; i++){
            cin>>arr[i];
        }
        
        string cmd;
        auto tree = BIT(arr.size());
        tree.build(arr);
        while(1) {
            cin>>cmd;
            if(cmd == "Query") {
                cin>>a>>b; 
                cout<<tree.query(b) - tree.query(a-1) <<endl;
            } else if(cmd == "Add") {
                cin>>a>>b;
                tree.update(a, b);
            } else if(cmd == "Sub") {
                cin>>a>>b;
                tree.update(a, -b);
            } else {
                break;
            }
        }
    }
    return 0;
}

