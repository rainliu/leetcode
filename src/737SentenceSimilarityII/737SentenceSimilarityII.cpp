class union_find{
    vector<int> id;
    vector<int> sz;
public:
    union_find(int N){
        id.resize(N);
        sz.resize(N);
        for(int i=0; i<N; ++i){
            id[i]=i;
            sz[i]=1;
        }
    }
    
    int find(int i){
        while(i!=id[i]){
            id[i]=id[id[i]];
            i=id[i];
        }
        return i;
    }
    bool connected(int p, int q){
        return find(p)==find(q);
    }
    void unioning(int p, int q){
        int i = find(p);
        int j = find(q);
        if(i==j) return;
        else if (sz[i]<sz[j]) {
            id[i]=j; sz[j]+=sz[i];
        }else{
            id[j]=i; sz[i]+=sz[j];
        }
    }
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if(words1.size()!=words2.size()) return false;
        
        unordered_map<string, int> m;
        int N = 0;
        for(const auto& pair : pairs){
            if(m.find(pair[0])==m.end()){
                m[pair[0]]=N++;
            }
            if(m.find(pair[1])==m.end()){
                m[pair[1]]=N++;
            }
        }
        union_find uf = union_find(N);
        for(const auto& pair : pairs){
            uf.unioning(m[pair[0]], m[pair[1]]);
        }
        
        for(int i=0; i<words1.size(); ++i){
            if(words1[i]==words2[i]) continue;
            if (m.find(words1[i])==m.end() || m.find(words2[i])==m.end()) return false;
            if(!uf.connected(m[words1[i]], m[words2[i]])) return false;
        }
        return true;
    }
};
