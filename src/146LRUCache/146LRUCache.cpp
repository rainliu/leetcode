class LRUCache {
    int capacity;
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> m; 
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        auto it = m[key];
        int value = it->second;
        l.erase(it);
        l.push_front({key,value});
        m[key]=l.begin();
        return value;
    }
    
    void put(int key, int value) {
        list<pair<int,int>>::iterator it;
        if(m.find(key)!=m.end() || l.size()>=capacity){
            if(m.find(key)!=m.end()){
                it = m[key];    
            }else{
                it = prev(l.end());
            }
            m.erase(it->first);
            l.erase(it);
        }
        l.push_front({key,value});
        m[key]=l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
