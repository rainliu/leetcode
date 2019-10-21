class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colormap(n, -1);
        for(int i=0; i<graph.size(); ++i){
            if(colormap[i]==-1){
                queue<pair<int,int>> q;               
                q.push({i, 0});
                colormap[i]=0;
                while(!q.empty()){
                    auto [v, color] = q.front(); q.pop();
                    for(const auto& u : graph[v] ){
                        if(colormap[u]==color){
                            return false;
                        }else if(colormap[u]==-1){
                            q.push({u, 1-color});
                            colormap[u]=1-color;
                        }
                    }
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> colormap[2];
        for(int i=0; i<graph.size(); ++i){
            if(colormap[0].find(i)==colormap[0].end()&&
               colormap[1].find(i)==colormap[1].end()){
                queue<pair<int,int>> q;               
                q.push({i, 0});
                colormap[0].insert(i);
                while(!q.empty()){
                    auto [v, color] = q.front(); q.pop();
                    for(const auto& u : graph[v] ){
                        if(colormap[color].find(u)!=colormap[color].end()){
                            return false;
                        }
                        if(colormap[1-color].find(u)==colormap[1-color].end()){
                            q.push({u, 1-color});
                            colormap[1-color].insert(u);
                        }
                    }
                }
            }
        }
        return true;
    }
};
