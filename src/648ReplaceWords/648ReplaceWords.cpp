struct Node{
    bool val;
    vector<Node*> next;
    Node(){
        next.resize(128, nullptr);
        val=false;
    }
};

class Solution {
    Node* put(Node* x, const string& word, int d){
        if(x==nullptr) x = new Node();
        if(d==word.size()){
            x->val = true;
        }else{
            x->next[word[d]] = put(x->next[word[d]], word, d+1);
        }
        return x;
    }
    int get(Node* x, const string& word, int d){
        if(x==nullptr) return -1;
        if(d<word.size()){
            if(x->val){
                return d;
            }else{
                return get(x->next[word[d]], word, d+1);
            }
        }
        return -1;
    }
    vector<string> split(const string& sentence, char dem){
        vector<string> result;
        int i = 0;
        int j = 0;
        while(j<sentence.size()){
            if(sentence[j]==dem){
                if(j-i>0){
                    result.push_back(sentence.substr(i, j-i));
                } 
                i=j+1;
            }
            ++j;
        }
        if(j-i>0){
            result.push_back(sentence.substr(i, j-i));
        } 
        return result;
    }
    string join(const vector<string>& words, char dem){
        ostringstream oss;
        for(int i=0; i<words.size(); ++i){
            if(i>0) oss<<dem;
            
            oss<<words[i];
        }
        return oss.str();
    }
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Node* root=nullptr;
        for(const auto& word : dict){
            root=put(root, word, 0);
        }
        auto words = split(sentence,' ');
        for(int i=0; i<words.size(); ++i){
            int d = get(root, words[i], 0);
            if(d!=-1){
                words[i] = words[i].substr(0, d);
            }
        }
        return join(words, ' ');
    }
};
