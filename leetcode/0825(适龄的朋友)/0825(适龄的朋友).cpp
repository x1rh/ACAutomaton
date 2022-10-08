class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int l=0, ans=0, r=0; 
        int n = ages.size();
        for(int i=0; i<ages.size(); ++i){
            int x = ages[i];
            if(x < 15) continue;
            while(l<n && 0.5*x+7 >= ages[l]) ++l;
            while(r+1<n && ages[r+1]<=x) ++r;
            ans += r - l;
        }
        return ans;
    }
};