class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
            return a[0] > b[0] || (a[0]==b[0] && a[1] < b[1]);
        });
        
        vector<vector<int>> result;
        for (int i=0; i<people.size(); ++i){
            auto it = result.begin();
            int k = people[i][1];
            while (k-->0) {
                ++it;
            }
            result.insert(it, people[i]);
        }
        return result;
    }
};
