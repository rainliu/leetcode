class union_find{
    vector<int> id;
    vector<int> sz;

public:
    union_find(int N) {
        id.resize(N);
        sz.resize(N);
        for(int i=0; i<N; ++i){
            id[i]=i;
            sz[i]=1;
        }
    }
    int root(int i){
        while(i!=id[i]){
            id[i]=id[id[i]];
            i=id[i];
        }
        return i;
    }
    bool connected(int p, int q){
        return root(p)==root(q);
    }
    void unioning(int p, int q) {
        int i = root(p);
        int j = root(q);
        if(i==j) return;
        else if(sz[i]<sz[j]){
            id[i]=j; sz[j]+=sz[i];    
        }else{
            id[j]=i; sz[i]+=sz[j];
        }
    }
    int finding(int p){
        return root(p);
    }
    int size(int p){
        int i = root(p);
        return sz[i];
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        union_find uf = union_find(stones.size());
        unordered_map<int, unordered_set<int>> mx;
        unordered_map<int, unordered_set<int>> my;
        for(int i=0; i<stones.size(); ++i) {
            mx[stones[i][0]].insert(i);
            my[stones[i][1]].insert(i);
        }
        for(const auto& p : mx){
            auto it = p.second.begin();            
            for(const auto& q: p.second){
                uf.unioning(*it, q);
            }
        }
        for(const auto& p : my){
            auto it = p.second.begin();            
            for(const auto& q: p.second){
                uf.unioning(*it, q);
            }
        }
        vector<bool> visited(stones.size(), false);
        int result = 0;
        for(int i=0; i<stones.size(); ++i){
            int j = uf.finding(i);
            if(!visited[j]){
                result+=uf.size(j)-1;
                visited[j]=true;
            }
        }
        return result;
    }
};
