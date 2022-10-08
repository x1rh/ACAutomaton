class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mm;
        for(int i=0; i<magazine.size(); ++i){
            mm[magazine[i]] += 1;
        }
        
        for(int i=0; i<ransomNote.size(); ++i){
            if(mm[ransomNote[i]] >= 1){
                mm[ransomNote[i]] -= 1;
            }
            else return false;
        }
        return true;

    }
};