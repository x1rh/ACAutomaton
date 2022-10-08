# 题目
https://leetcode-cn.com/problems/longest-duplicate-substring/


# 题意
从一个字符串中，找到一个子串，这个子串出现了不止一次，重复子串可以有部分重叠。要求找到最长的子串。


# 思路
1. 二分子串长度，越长越好
2. 快速判断长度为L的子串是否重复出现。使用Rabin-Karp算法，计算每个长度为L的子串的哈希值，保存到set中。


```cpp
typedef unsigned long long ull;

class Solution {
public:
    int check(string& s, int len){
        ull p = 31;
        ull hash = 0;
        ull power = 1;

        for(int i=0; i<len; ++i) {
            hash = hash * p + (s[i]-'a');
            power *= p;
        }

        unordered_set<ull> seen{hash};
        for(int i=len; i<s.size(); ++i){
            hash = hash * p - power*(s[i-len]-'a') + (s[i]-'a');
            if(seen.count(hash)){
                return i-len+1;
            }
            seen.insert(hash);
        }
        return -1;
    }


    string longestDupSubstring(string s) {
        int l = 0;
        int r = s.size() - 1;
        int mid, res;
        int ans = -1;
        int len = 0;

        while(l <= r){
            mid = l + ((r-l)>>1);
            res = check(s, mid);
            if(res != -1){
                ans = res;
                len = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        if(ans == -1) return "";
        else return s.substr(ans, len);
    }
};
```

解法来自： https://leetcode-cn.com/problems/longest-duplicate-substring/solution/wei-rao-li-lun-rabin-karp-er-fen-sou-suo-3c22/  

但是这个没有做哈希冲突处理，用了隐式的模运算。解决这个问题的一个方法是，每当找到两个一样的哈希值时，进行一个strcmp，但这样速度会慢。  

更好的做法是后缀数组？

# golang 
```go
const (
    p int = 31
)

func longestDupSubstring(s string) string {
    n := len(s)
    l := 1
    r := n

    pre := make([]int, n+1)
    pow := make([]int, n+1)
    pre[0] = 0 
    pow[0] = 1 
    for i:=1; i<=n; i++ {
        pre[i] = pre[i-1] * p + int(s[i-1] - 'a')
        pow[i] = pow[i-1] * p
    }

    end := -1
    for l <=r {
        mid := (l + r) / 2

        ok := false 
        vis := make(map[int]struct{})
         
        x := pre[mid]
        vis[x] = struct{}{}
        for i:=mid; i<n; i++ {
            x = x * p - int(s[i-mid] - 'a') * pow[mid] + int(s[i] - 'a')

            _, ok = vis[x]; if ok {
                end = i + 1
                break 
            } else {
                vis[x] = struct{}{}
            }
        }

        if ok {
            l = mid + 1 
        } else {
            r = mid - 1 
        }
    }
    if end == -1 {
        return "" 
    } else {
        return s[end-r:end]
    }
}
```