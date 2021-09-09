# 题目
`https://leetcode-cn.com/problems/text-justification/`


# 思路
模拟，细节如下：
- 从左往右遍历数组
- 每行尽可能多的放单词，空格先均匀分，然后再从左往右分
- 最后一行特殊处理：左对齐，注意第3个样例


```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size(), sz=0;
        int cnt = maxWidth;
        vector<vector<string>> ret;
        ret.push_back(vector<string>());
        for(int i=0; i<n; ++i){
            sz = words[i].size();
            if(cnt < sz){
                cnt = maxWidth;
                ret.push_back(vector<string>());
            }

            ret.back().push_back(words[i]);
            cnt -= sz + 1;
        }
        vector<string> ans;
        for(int i=0; i<ret.size(); ++i){
            if(ret[i].size() == 1){
                int sz = static_cast<int>(ret[i][0].size());
                ans.push_back(ret[i][0] + string(maxWidth-sz, ' '));
                continue;
            }

            int sz = 0;
            for(int j=ret[i].size()-1; j>=0; --j){
                sz += static_cast<int>(ret[i][j].size());
            }
            int left = maxWidth - sz;
            int avg = left / (static_cast<int>(ret[i].size() - 1));
            vector<int> blank(ret[i].size()-1, avg);
            int left_2 = left - avg * static_cast<int>(ret[i].size()-1);
            for(int j=0; j<left_2; ++j){
                blank[j] += 1;
            }
            string retval = ret[i][0];
            if(i==ret.size()-1){
                for(int j=1; j<ret[i].size(); ++j){
                    retval = retval + string(" ");
                    retval = retval + ret[i][j];
                }
                retval = retval + string(maxWidth-retval.size(), ' ');
            }
            else{
                for(int j=1; j<ret[i].size(); ++j){
                    retval = retval + string(blank[j-1], ' ');
                    retval = retval + ret[i][j];
                }
            }
            ans.push_back(retval);
        }
        return ans;
    }
};
```