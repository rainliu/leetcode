class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        multiset<int> s;
        for(auto h : hand) {
            s.insert(h);
        }
        while(s.size()>=W) {
            auto p = s.begin();
            int v = *p;
            for(int u=v; u<v+W; ++u){
                auto p = s.find(u);
                if(p != s.end()){
                    s.erase(p);
                }else{
                    return false;
                }
            }
        }
        
        return s.size()==0;
    }
};
