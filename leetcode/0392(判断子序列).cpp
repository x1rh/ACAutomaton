/*

解法一：暴力

*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) return true;
        for(int i=0; i<t.size(); ++i){
            if(s[0] == t[i]){
                int jj = i+1;
                int kk = 1;
                while(kk < s.size() && jj<t.size()){
                    if(s[kk] == t[jj]){
                        ++kk;
                        ++jj;
                    }
                    else{
                        ++jj;
                    }
                }
                if(kk == s.size()){
                    return true;
                }
            }
        }
        return false;
    }
};


/*

解法二：双指针，时间复杂度为O(m+n)

子序列匹配与子串匹配不同：
子串匹配失败后，两者指针都需要变化，而子序列匹配失败后只需要移动一个指针即可。

*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0; 
        int j=0;
        while(i<s.size() && j<t.size()){
            if(s[i] == t[j]){
                ++i;
                ++j;
            }
            else{
                ++j;
            }
        }
        if(i == s.size()){
            return true;
        }
        else{
            return false;
        }
    }
};

/*

解法三：
利用dp打表，节约每一次查找的时间，使得查找花费变为O(1)

记n = t.size()
dp[n][26]

dp[i][j]表示字符串t下标为i时，字符串t中下一个字符'a'+j的位置


dp[i][t[i+1]-'a'] = i+1



所有子序列问题都可以用类似的思想，把序列“拍扁”, 记录第一次出现的元素

*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() ==0 ) return true;
        vector<vector<int>> dp(t.size()+1, vector<int>(26, -1));
        for(int i=t.size()-1; i>=0; --i){
            dp[i] = dp[i+1];
            if(i==t.size()-1) continue;
            dp[i][t[i+1]-'a'] = i+1;
        }

        int i=0;
        int j=0;
        while(i != -1){
            if(s[j] == t[i]){
                ++j;
                if(j == s.size()) break;
            }
            i = dp[i][s[j] - 'a'];            
        }
        if(j == s.size()){
            return true;
        }
        else{
            return false;
        }
    }
};