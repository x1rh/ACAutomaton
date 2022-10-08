# 题目
[715. Range 模块](https://leetcode.cn/problems/range-module/)

# 题意
要求以`log(n)`复杂度添加区间，删除区间，查询区间

# 思路
cpp使用set暴力模拟，单一操作复杂度为`log(n)`

```cpp
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
```