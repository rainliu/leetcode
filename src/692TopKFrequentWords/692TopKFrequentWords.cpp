class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;        
        for (const string& word : words) {
            m[word]++;
        }
        auto cmp = [](const auto& a, const auto& b) {
            return a.second > b.second || (a.second==b.second && a.first < b.first);
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        for (const auto& p : m) {
            pq.push(p);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> result;
        while (!pq.empty()) {
            auto p = pq.top();
            string s = p.first;
            pq.pop();
            result.push_back(s);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
