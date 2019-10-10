class MyHashMap {
    vector<list<pair<int,int>>> m;
    static constexpr int HASH = 10001;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        m.resize(HASH);   
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash = key % HASH;
        auto& p = m[hash];
        auto it = std::find_if(p.begin(), p.end(), [=](const auto& p) { return p.first==key; });
        if(it==p.end()){
            p.push_back({key, value});
        }else{
            it->second = value;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hash = key % HASH;
        const auto& p = m[hash];
        auto it = std::find_if(p.begin(), p.end(), [=](const auto& p) { return p.first==key; });
        if(it==p.end()){
            return -1;
        }else{
            return it->second;
        }
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hash = key % HASH;
        auto& p = m[hash];
        auto it = std::find_if(p.begin(), p.end(), [=](const auto& p) { return p.first==key; });
        if(it!=p.end()){
            p.erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
