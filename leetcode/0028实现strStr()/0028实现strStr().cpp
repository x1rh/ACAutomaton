/*
方法一：暴力
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){
            return 0;
        }
        for(int i=0; i<haystack.size(); ++i){
            if(haystack[i] != needle[0]) continue;
            else{
                int ii=i+1;
                int jj=1;
                while(ii<haystack.size() && jj<needle.size() && haystack[ii]==needle[jj]){
                    ++ii;
                    ++jj;
                }
                if(jj == needle.size()){
                    return i;
                }
            }
        }
        return -1;
    }
};


/*
方法二：KMP
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        vector<int> pmt(needle.size(), 0);
        for(int i=1, j=0; i<needle.size(); ++i){
            while(j>=0 && needle[i]!=needle[j]){
                j = (j!=0)?pmt[j-1]:-1;
            }
            pmt[i] = ++j;
        }
        for(int i=0, j=0; i<haystack.size(); ++i){
            while(j>=0 && haystack[i]!=needle[j]){
                j = (j!=0)?pmt[j-1]:-1;
            }
            ++j;
            if(j == needle.size()){
                return i-j+1;
            }
        }
        return -1;
    }
};