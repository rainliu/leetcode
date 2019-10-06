class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<unordered_set<int>> indegree (n,unordered_set<int>{});
        vector<unordered_set<int>> outdegree(n,unordered_set<int>{});
        for(int i=0; i<n; ++i) {
            for(auto j: graph[i]){
                outdegree[i].insert(j);
                indegree[j].insert(i);
            }
        }
        vector<int> result;
        
        queue<int> q;
        for(int i=0; i<n; ++i){
            if(outdegree[i].empty()) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int i = q.front(); q.pop();
            result.push_back(i);
            for(int j : indegree[i]) {
                outdegree[j].erase(i);
                if(outdegree[j].empty()){
                    q.push(j);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};
