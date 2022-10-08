# 题目
`https://leetcode-cn.com/problems/fizz-buzz/`


# 思路
模拟即可。

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i=1; i<=n; ++i){
            if((i%3==0) && (i%5==0)){
                ans.push_back("FizzBuzz");
            }
            else if(i%3==0){
                ans.push_back("Fizz");
            }
            else if(i%5==0){
                ans.push_back("Buzz");
            }
            else{
                ostringstream oss;
                oss<<i;
                ans.push_back(oss.str());
            }
        }
        return ans;
    }
};
```