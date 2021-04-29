class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> mp;
        for(int i=0; i<numbers.size(); ++i){
            mp[numbers[i]]++;
            if(mp[numbers[i]] > numbers.size()/2){
                return numbers[i];
            }
        }
        return 0;
    }
};