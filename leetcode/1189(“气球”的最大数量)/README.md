# 题目
[1189-“气球”的最大数量](https://leetcode-cn.com/problems/maximum-number-of-balloons/)

# 题意
求字符串中的字符能组成多少个balloon单词

# 思路
计数即可，对`l`和`n`除2，最少的字符决定了balloon的个数

# 代码
cpp版
```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mp{{'b', 0}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0} };
        for(auto &x : text ){
            if(mp.find(x) != mp.end()){
                mp[x] += 1;
            }
        }

        int _min = INT_MAX;
        char c;
        for(auto &[k, v] : mp){
            if(v < _min){
                _min = v;
                c = k;
            }
        }
        if(c == 'o' || c == 'l'){
            return _min / 2;
        }
        else {
            return min(min(mp['o'], mp['l'])/2, _min);
        }
    }
};

```



Go版
```cpp
func min(a, b int) int {
    if a < b {
        return a
    } else {
        return b
    }
}

func maxNumberOfBalloons(text string) int {
    mp := make(map[rune]int)
    mp['b'] = 0
    mp['a'] = 0
    mp['l'] = 0
    mp['o'] = 0
    mp['n'] = 0

    for _, x := range text {
        _, ok := mp[x]; if ok {
            mp[x] += 1
        }
    }


    minCnt := 0x3f3f3f3f
    minKey := '0'

    for k, v := range mp {
        if v < minCnt {
            minCnt = v
            minKey = k
        }       
    }

    if minKey == 'l' || minKey == 'o' {
        return minCnt / 2;
    } else {
        return min(min(mp['o'], mp['l'])/2, minCnt)
    }

}
```
看了一下官方答案，感觉我写的太啰嗦了。。。

