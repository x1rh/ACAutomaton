class Solution {
public:

    string licenseKeyFormatting(string s, int k) {
        int kase = 0;
        string ans;
        int cnt = 0;
        for(auto &x : s){
            if(isdigit(x) || isalpha(x)){
                ++cnt;
            }
        }

        int l = cnt % k;

        for(int i=0; i<s.size(); ++i){
            char x = s[i];
            
            if(s[i] == '-') continue;

            if(l!=0 && kase==l){
                ans += '-';
                kase = 0;
                l = 0;
            }
            else if(kase == k){
                ans += '-';
                kase = 0;
            }


            if(('0'<=x && x<='9') || ('A'<=x && x<='Z')){
                ans += s[i];
            }
            else if('a'<=x && x<='z'){
                ans += static_cast<char>('A'+(x-'a'));
            }
            ++kase;
            
        }
        return ans;
    }
};