/*

字符串a和字符串b的最长公共子串

注意点：子串指连续的串

定义前缀子串的含义：字符串a的前缀子串指的是在字符串a中从下标i开始往左取任意长度的连续子串，记为a_i

定义dp[i][j]表示字符串a的前缀子串a_i与字符串b的前缀子串b_j的最长公共子串长度。
我们用一个全局的maxLength记录最长连续子串，再用一个idx记录这个连续子串的末尾下标，基于这两个条件即可求出最长连续子串


转移方程：
(1)dp[i][j] = dp[i-1][j-1] + 1; if a[i] == b[j]
(2)dp[i][j] = 0; if a[i] != b[j]     

初始化：
对转移方程1：要求dp[i-1][j-1]提前被构造
对转移方程2：要求dp[i-1][j], dp[i][j-1]提前被构造
上面两个条件取并集：初始化dp[0][0...n]和dp[0...m][0]即可。

dp矩阵构造方法：
按i从0到str1.size(), j从0到str2.size()遍历即可

*/


class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        if(!str1.size() || !str2.size()) return string();
        vector<vector<int>> dp(str1.size(), vector<int>(str2.size()));
        
        for(int i=0; i<str1.size(); ++i){
            if(str1[i] == str2[0]){
                dp[i][0] = 1;
            }
        }
        
        for(int i=0; i<str2.size(); ++i){
            if(str1[0] == str2[i]){
                dp[0][i] = 1;
            }
        }
        
        int maxLength = 0, idx=-1;
        for(int i=1; i<str1.size(); ++i){
            for(int j=1; j<str2.size(); ++j){
                if(str1[i] == str2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    if(maxLength < dp[i][j]){
                        maxLength = dp[i][j];
                        idx = i;
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return str1.substr(idx-maxLength+1, maxLength);
    }
};