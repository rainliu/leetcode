class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, vector<int>> dx;
        map<int, vector<int>> dy;
        for (const auto& point : points) {
            dx[point[0]].push_back(point[1]);
            dy[point[1]].push_back(point[0]);
        }
        int global = numeric_limits<int>::max();
        for(auto p : dx) {
            int x1 = p.first;
            auto ys = p.second;
            for(int i=0; i<int(ys.size())-1; ++i){
                int y1 = ys[i];
                for(int j=i+1; j<ys.size(); ++j){
                    int y2 = ys[j];
                    auto q = dy.find(y2);
                    if(q!=dy.end()){
                        auto xs2 = q->second;
                        for(int k=0; k<xs2.size(); ++k){
                            int x2 = xs2[k];
                            if(x2>x1){
                                auto r = dy.find(y1);
                                if(r!=dy.end()){
                                    auto xs1 = r->second;
                                    for(int l=0; l<xs1.size(); ++l){
                                        if(xs1[l]==x2){
                                            global = min(global, abs((y2-y1)*(x2-x1)));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }        
        
        return global == numeric_limits<int>::max() ? 0 : global;
    }
};
