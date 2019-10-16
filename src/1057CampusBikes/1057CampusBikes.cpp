class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        map<int, vector<pair<int, int>>> distance2pairs;
        for(int i=0; i<workers.size(); ++i){
            for(int j=0; j<bikes.size(); ++j){
                int distance = abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1]);
                distance2pairs[distance].push_back({i,j});
            }
        }
        unordered_set<int> used_workers;
        unordered_set<int> used_bikers;
        
        int count = workers.size();
        vector<int> result(count, 0);
        for(auto& [distance, pairs] : distance2pairs) {
            sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
                return a.first < b.first || (a.first==b.first && a.second < b.second);    
            });
            for(const auto& [worker, biker] : pairs) {
                if(used_workers.find(worker) == used_workers.end() &&
                   used_bikers.find(biker) == used_bikers.end()) {
                    used_workers.insert(worker);
                    used_bikers.insert(biker);
                    result[worker]=biker;
                    if(--count==0){
                        return result;
                    }
                }
            }
        }
        return result;
    }
};
