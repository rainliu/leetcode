struct Node{
    vector<Node*> next;
    Node(){
        next.resize(2, nullptr);
    }
};

class Solution {
    Node* put(Node* x, int num, int d){
        if(x==nullptr) x = new Node();
        if(d>=0){
            int c = (num>>d)&0x1;
            x->next[c] = put(x->next[c], num, d-1);
        }
        return x;
    }
    
    int get(Node* x, int num){
        int local = 0;
        for(int d=31; d>=0; --d){
            int c = (num>>d)&0x1;
            if(x->next[1-c]!=nullptr){
                local |= 1<<d;
                x = x->next[1-c];
            }else{
                x = x->next[c];
            }
        }
        return local;
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        Node* root = nullptr;
        for(const auto& num : nums){
            root = put(root, num, 31);
        }
        int global = 0;
        for(const auto& num : nums){
            global = max(global, get(root, num));
        }
        return global;
    }
};

class Solution {
private:
    struct Trie{
        struct Trie *child[2];
        Trie(){
            child[0]=child[1]=nullptr;
        }
    };
    
    struct Trie* insert(struct Trie* node, int x, int i){
        if(node==nullptr) node = new Trie();
        if(i==0) {node->child[(x>>i)&0x1] = new Trie(); return node;}
        node->child[(x>>i)&0x1] = insert(node->child[(x>>i)&0x1], x, i-1);
        return node;
    }
    
    int search(struct Trie* node, int x){
        int local = 0;
        for(int i=31; i>=0; --i){
            int j = (x>>i)&0x1 ? 0 : 1;
            local <<= 1;
            if(node->child[j]){
                node = node->child[j];
                local |= 1;
            }else{
                node = node->child[!j];
            }
        }
        return local;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        auto root = new Trie();
        for(auto x: nums){
            root=insert(root, x, 31);
        }
        int global=0;
        for(auto x: nums){
            global = max(global, search(root, x));
        }
        return global;
    }
};
