struct Node{
    optional<int> val;
    vector<Node*> next;
    Node(){
        next.resize(128, nullptr);
        val = {};
    }
};

class MapSum {
    Node* root;
    
    Node* put(Node* x, const string& key, int val, int d){
        if(x==nullptr) x = new Node();
        if(d==key.size()){
            x->val = val;
        }else{
            x->next[key[d]] = put(x->next[key[d]], key, val, d+1);
        }
        return x;
    }
    
    int get(const Node* x){
        if(x==nullptr) return 0;
        int sum = 0;
        if(x->val){
            sum += *(x->val);
        }
        for(const auto& next : x->next){
            sum+=get(next);
        }
        return sum;
    }
    const Node* get(const Node* x, const string& prefix, int d){
        if(x==nullptr) return nullptr;
        if(d==prefix.size()){
            return x;
        }else{
            return get(x->next[prefix[d]], prefix, d+1);
        }
    }
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = nullptr;
    }
    
    void insert(string key, int val) {
        root=put(root, key, val, 0);
    }
    
    int sum(string prefix) {
        auto x = get(root, prefix, 0);
        return get(x);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
