# Go
```go
type pair struct {
    to, d int 
}

type G struct {
    g [][]pair 
    n int 
}

func (g *G) prim(start int) int{
    inf := 0x3f3f3f3f 
    dist := make([]int, g.n)
    for i:=0; i<g.n; i++ {
        dist[i] = inf 
    }
    vis := make([]bool, g.n)
    dist[start] = 0 
    res := 0

    for i:=0; i<g.n; i++ {
        to := -1 
        min := inf 
        for j:=0; j<g.n; j++ {
            if !vis[j] && dist[j] < min {
                to = j
                min = dist[j] 
            }        
        }

        if to == -1 {
            // 不连通
        }

        res += min 
        vis[to] = true 
        for j:=0; j<len(g.g[to]); j++ {
            u := g.g[to][j].to
            d := g.g[to][j].d 
            if !vis[u] && dist[u] > d {
                dist[u] = d 
            } 
        }
    }
    return res
}
```

# CPP 
```cpp
class G {
public:
    struct node {
        int to, d;
        node(){}
        node(int to, int d):to(to), d(d){}
        bool operator< (const node& rhs) const {
            return this->d < rhs.d;
        }
    };

    int n; 
    const static int inf = 0x3f3f3f3f;
    vector<vector<node>> g;

    G(int n):n(n) {
        g = vector<vector<node>>(n, vector<node>());
    }

    int prim(int start) {
        int res = 0; 
        vector<int> d(n, inf);
        vector<bool> v(n, false);

        d[start] = 0; 
        for(int i=0; i<n; i++) {
        
            int to = -1;
            int max_ = inf;
            for(int j=0; j<n; j++) {
                if(!v[j] && d[j] < max_){
                    max_ = d[j];
                    to = j; 
                }
            }
            
            if(to==-1) {
                //return -1; // 未连通
            } 
            
            v[to] = true; 
            res += d[to];
            for(int j=0; j<g[to].size(); j++) {
                int u = g[to][j].to;
                int c = g[to][j].d;
                if(!v[u] && c < d[u]) {
                    d[u] = c;
                }
            }
        }

        return res;
    }
};
```