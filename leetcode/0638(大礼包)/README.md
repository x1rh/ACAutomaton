# 题目
`https://leetcode-cn.com/problems/shopping-offers/`

# 思路
- dfs，每种礼包可以选[0, 无穷个], 则dfs完成既可以有答案。
- 别忘了回溯


```cpp
class Solution {
public:
    static bool cmp(vector<vector<int>> &lhs, vector<vector<int>>&rhs){
        return lhs.back() < rhs.back();
    }


    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {

        int ans = INT_MAX;

        function<void(int, vector<int>, int)> dfs = [&](int si, vector<int> left, int cnt){
            if(si >= special.size()){
                for(int i=0;  i<left.size(); ++i){
                    if(left[i] != 0){
                        cnt += left[i] * price[i];
                    }
                }
                if(cnt < ans){
                    ans = cnt;
                }
                return ;
            }
            else{
                for(int i=0; ; ++i){
                    
                    if(i==0){
                        dfs(si+1, left, cnt);
                    }
                    else{
                        vector<int> backup = left;
                        vector<int> nv = special[si];
                        for(int j=0; j<nv.size()-1; ++j){
                            nv[j] *= i;
                            if(nv[j] > left[j]){
                                return;
                            }
                            else{
                                left[j] -= nv[j];
                            }
                        }
                        dfs(si+1, left, cnt+nv.back()*i);
                        left = backup;
                    }
                }
            }
        };

        dfs(0, needs, 0);
        return ans;
    }
};
```