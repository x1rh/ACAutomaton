class CountIntervals {
public:
    typedef pair<int, int> pii;    
    set<pii> s;
    int cnt;

    CountIntervals() {
        cnt = 0;
    }
    
    void add(int left, int right) {
        int l = left;
        int r = right;
        auto it = s.lower_bound(pii(left-1, -1));
        while (it != s.end()) {
            if (it->second > right + 1) break;
            l = min(l, it->second);
            r = max(r, it->first);
            cnt -= it->first - it->second + 1;
            s.erase(it++);
        }
        s.insert(pii(r, l));
        cnt += r - l + 1;
    }
    
    int count() {
        return cnt;
    }
};