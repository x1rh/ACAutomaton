class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mp{{'b', 0}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0} };
        for(auto &x : text ){
            if(mp.find(x) != mp.end()){
                mp[x] += 1;
            }
        }

        int _min = INT_MAX;
        char c;
        for(auto &[k, v] : mp){
            if(v < _min){
                _min = v;
                c = k;
            }
        }
        if(c == 'o' || c == 'l'){
            return _min / 2;
        }
        else {
            return min(min(mp['o'], mp['l'])/2, _min);
        }
    }
};
