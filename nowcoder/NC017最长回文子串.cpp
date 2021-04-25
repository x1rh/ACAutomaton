/*
要明确回文串有两种形式： abc, abba

解法1：
暴力最坏为接近O(n^2), 当整个字符串都是同一个字母时，其他时候暴力算法的表现其实还是很好的。

解法2：
dp， 时间复杂度为O(n^2)
转移方程：
定义dp[i][j]表示下标i到j的子串是否为回文串，是为true。

(1) dp[i][j] = dp[i+1][j-1] && (A[i]==A[j])
(2) dp[i][i] = true

dp数组构造方法，要求dp[i+1][j-1]先于dp[i][j]被构造， 
则枚举j，对0<= i <= j 进行遍历，i从j枚举到0，这样可以保证构造是正确的


解法3：
manacher    时间复杂度为O(n)


*/

class Solution {
public:
    
    void find(string &A, int &le, int &ri){
        while(le>=0 && ri<A.size()){
            if(A[le] == A[ri]){
                --le;
                ++ri;
            }
            else{
                break;
            }
        }
        ++le;
        --ri;
    }
    
    int getLongestPalindrome(string A, int n) {
        int ans = 0;
        for(int i=0; i<n; ++i){
            int le = i-1;
            int ri = i+1;
            find(A, le, ri);                  
            ans = max(ans, ri-le+1);
            if(i+1<A.size() && A[i]==A[i+1]){
                le = i-1;
                ri = i+2;
                find(A, le, ri);
                ans = max(ans, ri-le+1);
            }
        }
        
        return ans;
    }
};


/*
* 解法2， dp
*/
class Solution {
public:
   
    int getLongestPalindrome(string A, int n) {
        int ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for(int i=0; i<n; ++i){
            dp[i][i] = true;
        }
        for(int j=1; j<n; ++j){
            for(int i=j-1; i>=0; --i){
                if(i==j-1 && A[i]==A[j]){
                    dp[i][j] = true;
                    ans = max(ans, 2);
                }
                else{
                    if(dp[i+1][j-1] && A[i]==A[j]){
                        dp[i][j] = true;
                        ans = max(ans, j-i+1);
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        return ans;
    }
};

/*
* 解法3
*/

