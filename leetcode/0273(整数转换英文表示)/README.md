# 题目
`https://leetcode-cn.com/problems/integer-to-english-words/solution/`

# 思路1. 直接按位数讨论
写了大半个小时，幸好1A了

```cpp
class Solution {
public:

    string dfs(int num, map<int, string>& mp){
        vector<int> d;
        int backup = num;
        while(backup){
            d.push_back(backup%10);
            backup /= 10;
        }
        reverse(d.begin(), d.end());

        int sz = d.size();
        if(sz == 1){
            return mp[num];
        }
        else if(sz == 2){
            if(0<=num && num<10){
                return mp[num];
            }
            if(10<=num && num<=19){
                return mp[num];
            }
            else{
                if(num%10==0){
                    return mp[num];
                }
                else{
                    return mp[d[0]*10] + " " + mp[d[1]];
                }
            }
        }
        else if(sz == 3){
            int nn = num - d[0] * 100;
            if(d[0] == 0){
                return dfs(nn, mp);
            }
            else if(nn == 0){
                return mp[d[0]] + " Hundred";
            }
            else{
                return mp[d[0]] + " Hundred " + dfs(nn, mp);
            }
        }
        else if(sz == 4){
            int nn = num - d[0] * 1000;
            if(d[0] == 0){
                return dfs(nn, mp);
            }
            else if(nn == 0){
                return mp[d[0]] + " Thousand";
            }
            else{
                return mp[d[0]] + " Thousand " + dfs(nn, mp);
            }
        }
        else if(sz == 5){
            int n1 = d[0]*10 + d[1];
            int n2 = num - n1 * 1000;
            if(n1 == 0){
                return dfs(n2, mp);
            }
            else if(n2 == 0){
                return dfs(n1, mp) + " Thousand";
            }
            else{
                return dfs(n1, mp) + " Thousand " + dfs(n2, mp);
            }
        }
        else if(sz == 6){
            int n1 = d[0]*100 + d[1]*10 + d[2];
            int n2 = num - n1 * 1000;
            if(n1 == 0){
                return dfs(n2, mp);
            }
            else if(n2 == 0){
                return dfs(n1, mp) + " Thousand";
            }
            else{
                return dfs(n1, mp) + " Thousand " + dfs(n2, mp);
            }
        }
        else if(sz == 7){
            int nn = num - d[0] * 1000000;
            if(d[0] == 0){
                return dfs(nn, mp);
            }
            else if(nn == 0){
                return mp[d[0]] + " Million";
            }
            else{
                return mp[d[0]] + " Million " + dfs(nn, mp);
            }
        }
        else if(sz == 8){
            int n1 = d[0] * 10 + d[1];
            int n2 = num - n1 * 1000000;
            if(n1 == 0){
                return dfs(n2, mp);
            }
            else if(n2 == 0){
                return dfs(n1, mp) + " Million";
            }
            else{
                return dfs(n1, mp) + " Million " + dfs(n2, mp);
            }
        }
        else if(sz == 9){
            int n1 = d[0]*100 + d[1]*10 + d[2];
            int n2 = num - n1 * 1000000;
            if(n1 == 0){
                return dfs(n2, mp);
            }
            else if(n2 == 0){
                return dfs(n1, mp) + " Million";
            }
            else{
                return dfs(n1, mp) + " Million " + dfs(n2, mp);
            }
        }
        else if(sz == 10){
            int nn = num - d[0] * 1000000000;
            if(d[0] == 0){
                return dfs(nn, mp);
            }
            else if(nn == 0){
                return mp[d[0]] + " Billion";
            }
            else{
                return mp[d[0]] + " Billion " + dfs(nn, mp);
            }
        }
        return "fuckyou";
    }

    string numberToWords(int num) {
        if(num == 0) return "Zero";

        map<int, string> mp;
        mp[0] = "";
        mp[1] = "One";
        mp[2] = "Two";
        mp[3] = "Three";
        mp[4] = "Four";
        mp[5] = "Five";
        mp[6] = "Six";
        mp[7] = "Seven";
        mp[8] = "Eight";
        mp[9] = "Nine";
        mp[10] = "Ten";
        mp[11] = "Eleven";
        mp[12] = "Twelve";
        mp[13] = "Thirteen";
        mp[14] = "Fourteen";
        mp[15] = "Fifteen";
        mp[16] = "Sixteen";
        mp[17] = "Seventeen";
        mp[18] = "Eighteen";
        mp[19] = "Nineteen";
        mp[20] = "Twenty";
        mp[30] = "Thirty";
        mp[40] = "Forty";
        mp[50] = "Fifty";
        mp[60] = "Sixty";
        mp[70] = "Seventy";
        mp[80] = "Eighty";
        mp[90] = "Ninety";


        return dfs(num, mp);
    }
};
```


# 思路2： 每3位一组