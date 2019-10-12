class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> m;
        for(int i=0; i<equations.size(); ++i){
            m[equations[i][0]][equations[i][1]] = values[i];
            m[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }
        vector<double> result;
        for(int i=0; i<queries.size(); ++i){
            if(m.find(queries[i][0])==m.end() || m.find(queries[i][1])==m.end()){
                result.push_back(-1.0);
            }else{
                unordered_set<string> visited;
                auto q = dfs(m, visited, queries[i][0], queries[i][1], 1.0);
                if(q.first){
                    result.push_back(q.second);
                }else{
                    result.push_back(-1.0);
                }
            }
        }
        return result;
    }
    
    pair<bool,double> dfs(const unordered_map<string, unordered_map<string, double>>& m, unordered_set<string>& visited, const string& s, const string& e, double result){
        visited.insert(s);
        if(s==e) return make_pair(true, result);
        
        auto it = m.find(s);
        if(it==m.end()) return make_pair(false, result);
        for(const auto& p : it->second){
            if(visited.find(p.first)==visited.end()){
                auto q = dfs(m, visited, p.first, e, result*p.second);
                if(q.first) return q;
            }
        }
        
        return make_pair(false, result);
    }
};
