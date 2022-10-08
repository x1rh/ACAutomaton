class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        for(int i=0; i<nums.size(); ++i){
            map<int, bool> vis;
            int j = i;
            vector<int> tmp;
            vis[i] = true;
            tmp.push_back(i);
            int z=0, f=0;
            if(nums[i] > 0) ++z;
            else ++f;
            while(true){
                j = (j+nums[j]+nums.size()) % nums.size();
                if(!vis[j]){
                    vis[j] = true;
                    tmp.push_back(j);
                    if(nums[j]>0) ++z;
                    else ++f;
                }
                else{
                    tmp.push_back(j);
                    break;
                }
            }
            if(tmp.size()>2 && (f==tmp.size()-1 || z==tmp.size()-1) && tmp[0]==tmp.back()){
                return true;
            }
        }
        return false;
    }
};