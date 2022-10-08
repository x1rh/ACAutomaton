class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 1;
        int ai=0, aj=0;

        for(int i=0; i<s.size(); ++i){
            int l = i-1;
            int r = i+1;
            if(l>=0 && r<s.size() && s[l]==s[r]){
                while(l>=0 && r<s.size() && s[l]==s[r]){
                    --l;
                    ++r;
                }
                if(ans < r-l-1){
                    ans = r-l-1;
                    ai = l+1;
                    aj = r-1;
                }
            }
        }
        

        for(int i=1; i<s.size(); ++i){
            if(s[i-1]==s[i]){
                int l = i-1;
                int r = i;
                if(l>=0 && r<s.size() && s[l]==s[r]){
                    while(l>=0 && r<s.size() && s[l]==s[r]){
                        --l;
                        ++r;
                    }
                    if(l==i-1 && r==i && ans<r-l+1){
                        ans = 2;
                        ai = i-1;
                        aj = i;
                    }
                    else if(ans < r-l-1 ){
                        ans = r-l-1;
                        ai = l+1;
                        aj = r-1;
                    }
                }
                
            }
        }

        return string(s.begin()+ai, s.begin()+aj+1);
    }
};