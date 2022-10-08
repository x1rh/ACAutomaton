class SegmentTree {
public:
    struct node {
       long long l, r, v, t;
       node() {
           t = EMPTY;
           v = 0;
           l = 0;
           r = 0;
       }
    };

    static const int EMPTY = 0x3f3f3f3f;
    vector<node> tree;

    SegmentTree() {
        tree.resize(2);
    }

    void pushdown(int p) {
        if(!tree[p].l) {
            tree.push_back(node());
            tree[p].l = tree.size() - 1;
        }
        if(!tree[p].r) {
            tree.push_back(node());
            tree[p].r = tree.size() - 1;
        }

        if(tree[p].t != EMPTY) {
            if(tree[tree[p].l].t != EMPTY) {
                tree[tree[p].l].t += tree[p].t;
            } else {
                tree[tree[p].l].t = tree[p].t;
            }

            if(tree[tree[p].r].t != EMPTY) {
                tree[tree[p].r].t += tree[p].t;
            } else {
                tree[tree[p].r].t = tree[p].t;
            }

            tree[tree[p].l].v += tree[p].t;
            tree[tree[p].r].v += tree[p].t;
            tree[p].t = EMPTY;
        }
    }

    void pushup(int p) {
        tree[p].v = max(tree[tree[p].l].v, tree[tree[p].r].v);
    }

    void update(int p, int a, int b, int l, int r, int x) {
        if(a<=l && r<=b) {
            if(tree[p].t != EMPTY) {
                tree[p].t += x;
            } else {
                tree[p].t = x;
            }
            tree[p].v += x;
        } else {
            int mid = (l + r) / 2;
            pushdown(p);
            if(a<=mid) update(tree[p].l, a, b, l, mid, x);
            if(mid<b) update(tree[p].r, a, b, mid+1, r, x);
            pushup(p); 
        }
    }
    
    long long query(int p, int a, int b, int l, int r) {
        if(a <= l && r <= b) {
            return tree[p].v;
        } else {
            int mid = (l + r) / 2;
            long long res = 0;
            pushdown(p);
            if(a <= mid) res = max(query(tree[p].l, a, b, l, mid), res);
            if(mid < b) res = max(query(tree[p].r, a, b, mid+1, r), res);
            pushup(p);
            return res;
        }
    }
};


class MyCalendarThree {
public:
    MyCalendarThree() {
        tree = new SegmentTree;
    }
    SegmentTree *tree;
    static const int INF = 1e9;
    
    int book(int start, int end) {
        tree->update(1, start+1, end, 1, INF+1, 1);
        return tree->tree[1].v;
    }
};
