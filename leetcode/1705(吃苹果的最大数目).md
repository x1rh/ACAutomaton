# 题目
https://leetcode-cn.com/problems/maximum-number-of-eaten-apples/

# 题意
第i天生成apples[i]个苹果，这apples[i]个苹果在days[i]这天变质。
现在每天吃一个苹果（如果有的话），请问能吃多少个苹果。


# 思路
用一个优先队列维护`(过期日期, 苹果个数)`这样的一个二元组。

分两步，第一步是前n天，第二步是n天后。

第一步中：  
- 对当前日期i，要求队列中的每一项的过期日期必须晚于i，否则pop。
- 将日期i产生的苹果入队。
- 如果此时队列非空，则消耗一个苹果，更新队列。

第二步中：  
- 处理每一个队列项
- 对于当前日期i，每个队列项的贡献是delta = min(过期日期-i, 苹果个数)


需要想清楚，同样过期日期，不同起始日期对这一步没有影响:
- 在第一步中，是考虑了的，`开始日期严格递增`
- 在第二步中，是考虑了的，其逻辑隐藏在`先过期的先吃了，但是由于有相同的结束日期，不影响最终结果`

总之，起始日期有影响，但是没有在代码中体现出来，这是这题的难点。

```cpp
typedef pair<int, int> pii;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        int last = 0;
        int ans = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(int i=0; i<n; ++i) {
            int ed = i + days[i];
            last = max(ed, last);
            while(!pq.empty() && pq.top().first<=i) pq.pop();
            if(apples[i]>0)
                pq.emplace(ed, apples[i]);
            
            if(!pq.empty()){
                auto tp = pq.top(); pq.pop();
                --tp.second;
                if(tp.second > 0){
                    pq.emplace(tp.first, tp.second);
                }
                ++ans;
            }
        }

        for(int i=n; i<=last;){
            while(!pq.empty() && pq.top().first<=i) pq.pop();
            if(pq.empty()) break;
            auto tp = pq.top(); pq.pop();
            int delta = min(tp.first-i, tp.second);
            i += delta;
            ans += delta;
        }
        return ans;
    }
};

```