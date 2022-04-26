# include <iostream>
# include <cassert>

using namespace std;

typedef long long ll;

ll id;
const int maxn = 9800000;  
const ll inf = 2e14;

struct node{
    ll l, r, x;
    node(){}
    node(ll l, ll r, ll x):l(l), r(r), x(x){}
}tree[maxn];


void insert(ll p, ll l, ll r, ll idx) {
    assert(id < maxn);
    if(l==r) {
        tree[p].x++;
    } else {
        ll mid = (l+r)>>1;
        if(idx<=mid) {
            if(!tree[p].l) {
                tree[p].l = ++id;
                tree[id].l = tree[id].r = tree[id].x = 0;
            }
            insert(tree[p].l, l, mid, idx);
        }
        if(mid<idx) {
            if(!tree[p].r) {
                tree[p].r = ++id;
                tree[id].l = tree[id].r = tree[id].x = 0;
            }
            insert(tree[p].r, mid+1, r, idx);
        }
        tree[p].x = tree[tree[p].l].x + tree[tree[p].r].x;
    }
}

ll query(ll p, ll a, ll b, ll l, ll r) {
    if(!p) {
        return 0;
    }
    if(a<=l && r<=b) {
        return tree[p].x;
    } else {
        ll res = 0;
        ll mid = (l+r)>>1;
        if(a<=mid) res += query(tree[p].l, a, b, l, mid);
        if(mid<b) res += query(tree[p].r, a, b, mid+1, r); 
        return res;    
    }
}


int main() {
    ll n, t, inp;
    while(cin>>n>>t) {
        id = 1;
        ll ans = 0;
        ll sum = 0;
        insert(1, -inf, inf, 0);
        for(int i=0; i<n; i++) {
            cin>>inp;
            sum += inp;
            ans += query(1, sum-t+1, inf, -inf, inf);
            insert(1, -inf, inf, sum);
        }
        cout<<ans<<endl;
    }
    return 0; 
}


