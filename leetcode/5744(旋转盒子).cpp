/*
按条件模拟即可
*/


class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> rot(box[0].size(), vector<char>(box.size(), '.'));
        for(int i=0; i<box.size(); ++i){
            for(int j=0; j<box[i].size(); ++j){
                rot[j][box.size()-i-1] = box[i][j];
            }
        }
        
        for(int j=0; j<rot[0].size(); ++j){
            for(int i=rot.size()-1; i>=0; --i){
                if(rot[i][j]=='#'){
                    int k = i+1;
                    bool flag = false;
                    while(k<rot.size()){
                        if(rot[k][j] == '.'){
                            flag = true;
                            ++k;
                        }
                        else{
                            break;
                        }
                    }
                    
                    
                    if(flag){
                        rot[k-1][j] = '#';
                        rot[i][j] = '.';
                    }
                    
                }
            }
        }
        
        return rot;
        
    }
};