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