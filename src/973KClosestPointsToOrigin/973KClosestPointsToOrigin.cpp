class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto cmp = [](const auto& a, const auto& b) {
            return a.first < b.first;    
        };
        priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, decltype(cmp)> pq(cmp);
        for(const auto& point : points) {
            pq.push({point[0]*point[0]+point[1]*point[1], point});
            if(pq.size()>K) {
                pq.pop();
            }
        }
        vector<vector<int>> results;
        while(!pq.empty()){
            auto [d, v] = pq.top(); pq.pop();
            results.push_back(v);
        }        
        return results;
    }
};
