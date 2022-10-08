class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if(people.size()==0) return 0;
        if(people.size()==1) return 1;
        sort(people.begin(), people.end());
        int i=0, j=people.size()-1;
        int ans = 0;
        while(i<j){
            if(people[j] + people[i] > limit){
                --j;
                ++ans;
            }
            else{
                --j;
                ++i;
                ++ans;
            }
        }
        if(i==j) ++ans;
        return ans;
    }
};