class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int,vector<pair<int,int>>> graph;
        for(const auto& time : times){
            graph[time[0]].push_back({time[1],time[2]});
        }
        
        vector<int> dist(N+1, numeric_limits<int>::max());
        dist[K] = 0;
        
        set<pair<int, int>> pq;
        pq.insert({dist[K], K});
        int d = 0;
        while(!pq.empty()){
            auto it = pq.begin();
            int u = it->second;
            d = it->first;
            pq.erase(it);
            --N;
            for(const auto& edge : graph[u]) {
                int v = edge.first;
                int l = edge.second;
                if(dist[v] > d + l){
                    auto it = pq.find({dist[v], v});
                    if( it != pq.end()){
                        pq.erase(it);
                    }
                    dist[v] = d + l;
                    pq.insert({dist[v], v});
                }
            }            
        }
        return N==0 ? d : -1; 
    }
};
