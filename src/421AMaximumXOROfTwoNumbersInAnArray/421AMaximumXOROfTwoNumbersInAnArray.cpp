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
