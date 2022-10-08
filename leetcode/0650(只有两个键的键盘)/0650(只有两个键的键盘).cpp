class Solution {
public:
    void dfs(int cp, int cost, int n, map<int, int>& mp){
        for(int i=2*cp; i<=n; i+=cp){
            if(n%i==0){
                int cn = cost+i/cp;
                auto it = mp.find(i);
                if(it != mp.end()){ 
                    if(cn < mp[i]){
                        mp[i] = cn;
                        dfs(i, cn, n, mp);
                    }
                }
                else{
                    mp[i] = cn;
                    dfs(i, cn, n, mp);
                }
            }
        }
    }


    int minSteps(int n) {
        map<int, int> mp;
        dfs(1, 0, n, mp);
        return mp[n];
    }
};