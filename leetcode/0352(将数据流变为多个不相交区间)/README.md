# 题目
`https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals/`

# 思路
- 题意：
  - 不停读取整数，维护整数所组成的区间。  
- 思路： 
  - 模拟即可，利用lower_bound()使得查找是log(n)
  - insert的开销底层实现并不是O(n)，注意插入的三种情况，以及合并的四种情况
  - 原地维护区间，使得getInterval()的时空开销等价于vector拷贝。 

```cpp
class SummaryRanges {
public:
    static bool cmp(const vector<int>& lhs, const vector<int>& rhs){
        if(lhs[0] < rhs[0]) return true;
        else if(lhs[0] == rhs[0]) {
            return lhs[1] < rhs[1];
        }
        else return false;
    }


    vector<vector<int>> vec;
    SummaryRanges() {
        vec.clear();
    }

    void addNum(int val) {
        vector<int> na = {val, val};
        auto it = lower_bound(vec.begin(), vec.end(), na, cmp);
        if(it == vec.end()){
            if(vec.empty()) vec.push_back(na);
            else if(vec.back()[1]+1 == val) vec.back()[1] = val;
            else if(vec.back()[1] < val) vec.push_back(na);
        }
        else{
            if((*it)[0]==na[0] && (*it)[1]==na[1]){

            }
            else{
                if(it==vec.begin()){
                    if((*it)[0]-1 == val){
                        (*it)[0] = val;
                    }
                    else if((*it)[0] == val){
                        
                    }
                    else{
                        vec.insert(vec.begin(), na);
                    }
                }
                else{
                    auto prev = it - 1;
                    if((*prev)[0]<= val && val<= (*prev)[1]){

                    }
                    else if((*prev)[1]==val || (*it)[0]==val){

                    }
                    else if( ((*prev)[1]+1)==val && (val+1)<(*it)[0] ){
                        (*prev)[1] = val;
                    }
                    else if( ((*prev)[1]+1)==val && (val+1)==(*it)[0]){
                        (*prev)[1] = (*it)[1];
                        vec.erase(it);
                    }
                    else if( ((*prev)[1]+1)<val && (val+1)==(*it)[0]) {
                        (*it)[0] = val;
                    }
                    else{
                        vec.insert(it, na);
                    }
                }
            }
        }
    }

    vector<vector<int>> getIntervals() {
        return vec;
    }
};
```