class RangeModule {
public:
    typedef pair<int, int> pii;
    set<pii> s;
    RangeModule() {
        s.clear();
    }

    void addRange(int left, int right) {
        int l = left;
        int r = right;
        auto it = s.lower_bound(pii(left, -1));
        while (it != s.end()) {
            if (it->second > right) break;
            l = min(l, it->second);
            r = max(r, it->first);
            s.erase(it++);
        }
        s.insert(pii(r, l));
    }
    
    bool queryRange(int left, int right) {
        auto it = s.upper_bound(pii(left+1, -1));
        if(it!=s.end() && it->second <= left && right <= it->first) {
            return true;
        } else {
            return false;
        }
    }
    
    void removeRange(int left, int right) {
        auto i = s.lower_bound(pii(left+1, -1));
        while(i != s.end()) {
            if(i->second >= right) break;        
            if(i->second < left) {
                s.insert(pii(left, i->second));
            } 
            if(i->first > right) {
                s.insert(pii(i->first, right));
            }
            s.erase(i++);
        }
        return ;
    }
};