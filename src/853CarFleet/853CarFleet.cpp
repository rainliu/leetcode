class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>> cars;
        for(int i=0; i<position.size(); ++i) {
            cars.push_back({position[i], float(target-position[i])/float(speed[i])});
        }
        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b){
            return a.first > b.first;
        });
        int count = 0;
        float time = -1.0;
        for(int i=0; i<cars.size(); ++i){
            if(cars[i].second > time) {
                ++count;
                time = cars[i].second;
            }
        }
        
        return count;
    }
};
