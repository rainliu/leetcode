class Solution {
    map<int, int> weights;
    vector<vector<int>> rects;
    int sum;
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        sum = 0;
        weights[sum] = 0;
        for(int i=0; i<rects.size(); ++i){
            sum += (rects[i][2]-rects[i][0]+1)*(rects[i][3]-rects[i][1]+1);
            weights[sum] = i+1;
        }
    }
    
    vector<int> pick() {
        if(sum==0) return vector<int>{};
        int weight = rand()%sum;
        auto it = weights.upper_bound(weight);
        int i = prev(it)->second;
        return vector<int>{rects[i][0]+(rand()%(rects[i][2]-rects[i][0]+1)),
                           rects[i][1]+(rand()%(rects[i][3]-rects[i][1]+1))};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
