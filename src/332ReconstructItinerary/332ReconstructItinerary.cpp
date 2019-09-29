// topological sort!!!
class Solution {
    const string FIRST_STOP_NAME = "JFK";
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;        
        map<string, multiset<string>> itinerary;
        for(auto& ticket : tickets) {
            itinerary[ticket[0]].insert(ticket[1]);
        }
        
        dfs(itinerary, result, FIRST_STOP_NAME);
        reverse(result.begin(), result.end());
        return result;
    }
    
    void dfs(map<string, multiset<string>>& itinerary, vector<string>& result, string stop){        
        while (itinerary[stop].size()) {
            auto next_stop = itinerary[stop].begin();
            string next_stop_name = *next_stop;
            itinerary[stop].erase(next_stop);
            dfs(itinerary, result, next_stop_name);
        }
        result.push_back(stop);
    }
};
