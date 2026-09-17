class LRUCache {
public:
    int size , curr;
    unordered_map<int , pair<int , int>> mpp;
    LRUCache(int capacity) {
        size = capacity;
        curr = 0;
    }
    
    int get(int key) {
        if(mpp.count(key) != 0){
            mpp[key].second = curr++;
            return mpp[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.count(key) == 0 && mpp.size() >= size){
            int mn = INT_MAX;
            int k;
            for(auto& i : mpp){
                if(mn > (int)i.second.second){
                    mn = i.second.second;
                    k = i.first;
                }
            }
            mpp.erase(k);
        }
        mpp[key].first = value;
        mpp[key].second = curr++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */