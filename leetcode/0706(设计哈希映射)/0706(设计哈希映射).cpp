class MyHashMap {
public:
    vector<list<pair<int, int>>> data;
    const int MOD = 2333;

    MyHashMap():data(2333) {

    }    
    
    void put(int key, int value) {
        int idx = key % MOD;
        for(auto it=data[idx].begin(); it!=data[idx].end(); ++it){
            if(it->first == key){
                it->second = value;
                return;
            }
        }
        data[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = key % MOD;
        for(auto it=data[idx].begin(); it!=data[idx].end(); ++it){
            if(it->first == key){
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = key % MOD;
        for(auto it=data[idx].begin(); it!=data[idx].end(); ++it){
            if(it->first == key){
                data[idx].erase(it);
                return;
            }
        }
    }
};
