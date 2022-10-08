/*
恶臭
*/

#include <iostream>
#include <vector>
using namespace std;

# define SEGMENT_TREE_MAX
# define SEGMENT_TREE_MIN
# define SEGMENT_TREE_SET
# define SEGMENT_TREE_INF 0x3f3f3f3f
# define SEGMENT_TREE_EMPTY SEGMENT_TREE_INF
# define SEGMENT_TREE_MIN_VAL (-SEGMENT_TREE_INF)
# define SEGMENT_TREE_MAX_VAL SEGMENT_TREE_INF
# define lson(p) tree[p].l
# define rson(p) tree[p].r
template<typename DataType, typename ResultType>
class SegmentTree{
public:
    struct node{
        int l, r;
        DataType addv, v;

        #ifdef SEGMENT_TREE_SET
        DataType setv;
        #endif

        # ifdef SEGMENT_TREE_MAX
        DataType max;
        #endif

        # ifdef SEGMENT_TREE_MIN
        DataType min;
        #endif

        node():l(0), r(0), addv(SEGMENT_TREE_EMPTY), v(0){
            #ifdef SEGMENT_TREE_SET
            setv = SEGMENT_TREE_EMPTY;
            #endif

            #ifdef SEGMENT_TREE_MAX
            max = SEGMENT_TREE_MIN_VAL;
            #endif

            #ifdef SEGMENT_TREE_MIN
            min = SEGMENT_TREE_MAX_VAL;
            #endif
        }
    };

    vector<node> tree;
    SegmentTree() {
        tree.resize(2);
    }

    void down(int p, int len) {
        if(!lson(p)) {
            tree.push_back(node());
            tree[p].l = tree.size() - 1;
        }
        if(!rson(p)) {
            tree.push_back(node());
            tree[p].r = tree.size() - 1;
        }

        #ifdef SEGMENT_TREE_SET
        if(tree[p].setv != SEGMENT_TREE_EMPTY) {
            tree[lson(p)].addv = tree[rson(p)].addv = SEGMENT_TREE_EMPTY;
            tree[lson(p)].setv = tree[rson(p)].setv = tree[p].setv;
            tree[lson(p)].v = tree[p].setv * (len - len / 2);
            tree[rson(p)].v = tree[p].setv * (len / 2);

            #ifdef SEGMENT_TREE_MAX
            tree[lson(p)].max = tree[rson(p)].max = tree[p].setv;
            #endif

            #ifdef SEGMENT_TREE_MIN
            tree[lson(p)].min = tree[rson(p)].min = tree[p].setv;
            #endif

            tree[p].setv = SEGMENT_TREE_EMPTY;
        }
        #endif

        if(tree[p].addv != SEGMENT_TREE_EMPTY) {
            if(tree[lson(p)].addv == SEGMENT_TREE_EMPTY) {
                tree[lson(p)].addv = tree[p].addv;
            } else {
                tree[lson(p)].addv += tree[p].addv;
            }

            if(tree[rson(p)].addv == SEGMENT_TREE_EMPTY) {
                tree[rson(p)].addv = tree[p].addv;
            } else {
                tree[rson(p)].addv += tree[p].addv;
            }

            tree[lson(p)].v += tree[p].addv * (len - len / 2);
            tree[rson(p)].v += tree[p].addv * (len / 2);

            #ifdef SEGMENT_TREE_MAX
            tree[lson(p)].max += tree[p].addv;
            tree[rson(p)].max += tree[p].addv;
            #endif

            #ifdef SEGMENT_TREE_MIN
            tree[lson(p)].min += tree[p].addv;
            tree[rson(p)].min += tree[p].addv;
            #endif

            tree[p].addv = SEGMENT_TREE_EMPTY;
        }
    }

    void up(int p) {
        tree[p].v = tree[lson(p)].v + tree[rson(p)].v;

        #ifdef SEGMENT_TREE_MAX
        tree[p].max = std::max(tree[lson(p)].max, tree[rson(p)].max);
        #endif

        #ifdef SEGMENT_TREE_MIN
        tree[p].min = std::min(tree[lson(p)].min, tree[rson(p)].min);
        #endif
    }

    void add(int p, int a, int b, int l, int r, DataType x) {
        if(a <= l && r <= b) {
            tree[p].v += (r - l + 1) * x;
            if(tree[p].addv == SEGMENT_TREE_EMPTY) {
                tree[p].addv = x;
            } else {
                tree[p].addv += x;
            }
        } else {
            int mid = (l + r) >> 1;
            down(p, r - l + 1);
            if(a <= mid) add(lson(p), a, b, l, mid, x);
            if(mid < b) add(rson(p), a, b, mid + 1, r, x);
            up(p);
        }
    }

    #ifdef SEGMENT_TREE_SET
    void set(int p, int a, int b, int l, int r, DataType x) {
        if(a <= l && r <= b) {
            tree[p].v = x * (r - l + 1);
            tree[p].addv = SEGMENT_TREE_EMPTY;
            tree[p].setv = x;
            tree[p].max = tree[p].min = x;
        } else {
            int mid = (l + r) >> 1;
            down(p, r - l + 1);
            if(a <= mid) set(lson(p), a, b, l, mid, x);
            if(mid < b) set(rson(p), a, b, mid + 1, r, x);
            up(p);
        }
    }
    #endif

    #ifdef SEGMENT_TREE_MAX
    DataType queryMax(int p, int a, int b, int l, int r) {
        if(a <= l && r <= b) {
            return tree[p].max;
        } else {
            DataType res = SEGMENT_TREE_MIN_VAL;
            int mid = (l + r) >> 1;
            down(p, r - l + 1);
            if(a <= mid) res = std::max(res, queryMax(lson(p), a, b, l, mid));
            if(mid < b) res = std::max(res, queryMax(rson(p), a, b, mid + 1, r));
            up(p);
            return res;
        }
    }
    #endif

    #ifdef SEGMENT_TREE_MIN
    DataType queryMin(int p, int a, int b, int l, int r) {
        if(a <= l && r <= b) {
            return tree[p].min;
        } else {
            DataType res = SEGMENT_TREE_MAX_VAL;
            int mid = (l + r) >> 1;
            down(p, r - l + 1);
            if (a <= mid) res = std::min(res, queryMin(lson(p), a, b, l, mid));
            if (mid < b) res = std::min(res, queryMin(rson(p), a, b, mid + 1, r));
            up(p);
            return res;
        }
    }
    #endif

    ResultType querySum(int p, int a, int b, int l, int r) {
        if(a <= l && r <= b) {
            return tree[p].v;
        } else {
            DataType res = 0;
            int mid = (l + r) >> 1;
            down(p, r - l + 1);
            if(a <= mid) res += querySum(lson(p), a, b, l, mid);
            if(mid < b) res += querySum(rson(p), a, b, mid + 1, r);
            up(p);
            return res;
        }
    }
};

int main() {
    SegmentTree<int, long long> tree;
    for(int i=0; i<10; i++) {
        tree.add(1, i+1, i+1, 1, 10, i+1);
    }
    cout<< "sum: " << tree.querySum(1, 1, 10, 1, 10) <<endl;
    cout<< "max: " << tree.queryMax(1, 1, 10, 1, 10) <<endl;
    cout<< "min: " << tree.queryMin(1, 1, 10, 1, 10) <<endl;
    for(int i=0; i<10; i++) {
        cout<<tree.querySum(1, i+1, i+1, 1, 10)<<endl;
    }
    cout<<tree.querySum(1, 1, 3, 1, 10)<<endl;
    cout<<tree.querySum(1, 3, 4, 1, 10)<<endl;

    tree.add(1, 1, 10, 1, 10, 1);
    cout<< "sum: " << tree.querySum(1, 1, 10, 1, 10) <<endl;
    cout<< "max: " << tree.queryMax(1, 1, 10, 1, 10) <<endl;
    cout<< "min: " << tree.queryMin(1, 1, 10, 1, 10) <<endl;
    for(int i=0; i<10; i++) {
        cout<<tree.querySum(1, i+1, i+1, 1, 10)<<endl;
    }

    return 0;
}