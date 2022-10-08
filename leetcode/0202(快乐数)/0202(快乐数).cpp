class Solution {
public:
    bool check(int n, map<int, bool>& vis){
            int t = 0;
            while(n){
                int g = n % 10;
                n/=10;
                t += g*g;
            }
            if(vis[t]){
                return false;
            }
            vis[t] = true;
            if(t!=1){
                return check(t, vis);
            }
            return true;
        }


    bool isHappy(int n) {
        map<int, bool> vis;
        return check(n, vis);
        
    }
};