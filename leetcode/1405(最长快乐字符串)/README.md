# 题目
`https://leetcode-cn.com/problems/longest-happy-string/`

# 题意
a个a, b个b，c个c，构造不含aaa、bbb、ccc的最长字符串


# 思路
贪心，每次往ans里添加个数最多的字母，如果前两个字符和当前字符相同，则替换为较少的那一个字符

```cpp
class Solution {
public:
    struct Node {
        int cnt;
        char x;
        Node(int cnt, char x):cnt(cnt), x(x){}
        bool operator<(const Node& rhs)const{
            return this->cnt > rhs.cnt;
        }
    };

    string longestDiverseString(int a, int b, int c) {
        vector<Node> arr = {Node(a, 'a'), Node(b, 'b'), Node(c, 'c')};
        ostringstream oss;
        while(1){
            sort(arr.begin(), arr.end());
            bool flag = false;
            for(auto &x : arr){
                if(x.cnt <= 0) break;

                int sz = oss.str().size();

                if(sz>=2 && oss.str()[sz-1]==x.x && oss.str()[sz-2]==x.x){
                    continue;
                }
                oss<<x.x;
                --x.cnt;
                flag = true;
                break;
            }
            if(!flag) break;

        }
        return oss.str();
    }
};
```


go版
```go
func longestDiverseString(a int, b int, c int) string {
	ans := []byte{}
	arr := []struct{x byte; cnt int}{{'a', a}, {'b', b}, {'c', c}}
	for {
		sort.Slice(arr, func(i, j int) bool {return arr[i].cnt > arr[j].cnt})
		flag := false
		for i, x := range arr{
			if x.cnt == 0 {
				break
			}
			sz := len(ans)
			if sz>=2 && ans[sz-1]==x.x && ans[sz-2]==x.x {
				continue
			}
			flag = true
			arr[i].cnt--
			ans = append(ans, x.x)
			break
		}
		if !flag {
			break
		}
	}
	return string(ans)
}
```