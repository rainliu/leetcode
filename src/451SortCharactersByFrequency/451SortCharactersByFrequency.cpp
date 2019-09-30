class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> charFrequency;
        for (auto&c : s) {
            charFrequency[c]++;
        }
        // default C++ priority_queue is MAX heap with std::less compare operator
        // therefore, here we need to implement less compare operator too.
        auto cmp = [](const auto& a, const auto& b) { return a.second < b.second; };
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(cmp)> q(cmp);
        
        for(const auto it: charFrequency) {
            q.push(it);
        }
        ostringstream oss;
        
        while(!q.empty()){
            auto p = q.top();
            for(int i=0; i<p.second; ++i){
                oss<<p.first;
            }
            q.pop();
        }
        
        return oss.str();
    }
};
