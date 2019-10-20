struct Node{
    bool val;
    vector<Node*> next;
    Node(){
        next.resize(26, nullptr);
        val = false;
    }
};

class MagicDictionary {
    Node* root;
    
    Node* put(Node* x, const string& word, int d){
        if(x==nullptr) x = new Node();
        if(d==word.size()){
            x->val = true;
        }else{
            int c = word[d]-'a';
            x->next[c] = put(x->next[c], word, d+1);
        }
        return x;
    }
    
    bool get(Node* x, const string& word, int d){
        if(x==nullptr) return false;
        if(d==word.size()){
            return x->val;
        }else{
            int c = word[d]-'a';
            return get(x->next[c], word, d+1);
        }
    }
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = nullptr;    
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(const auto& word : dict){
            root = put(root, word, 0);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        string word2 = word;
        for(int i=0; i<word.size(); ++i){
            for(int j=0; j<26; ++j){
                if(j==word[i]-'a') continue;
                word2[i] = j+'a';
                if(get(root, word2, 0)) return true;
            }
            word2[i]=word[i];
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
