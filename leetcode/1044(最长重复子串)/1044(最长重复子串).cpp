typedef unsigned long long ull;

class Solution {
public:
    int check(string& s, int len){
        ull p = 31;
        ull hash = 0;
        ull power = 1;

        for(int i=0; i<len; ++i) {
            hash = hash * p + (s[i]-'a');
            power *= p;
        }

        unordered_set<ull> seen{hash};
        for(int i=len; i<s.size(); ++i){
            hash = hash * p - power*(s[i-len]-'a') + (s[i]-'a');
            if(seen.count(hash)){
                return i-len+1;
            }
            seen.insert(hash);
        }
        return -1;
    }


    string longestDupSubstring(string s) {
        int l = 0;
        int r = s.size() - 1;
        int mid, res;
        int ans = -1;
        int len = 0;

        while(l <= r){
            mid = l + ((r-l)>>1);
            res = check(s, mid);
            if(res != -1){
                ans = res;
                len = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        if(ans == -1) return "";
        else return s.substr(ans, len);
    }
};