class SnapshotArray {
    vector<vector<pair<int,int>>> storage;
    int snap_id;
public:
    SnapshotArray(int length) {
        snap_id = 0;
        storage.resize(length, vector<pair<int,int>>{});
    }
    
    void set(int index, int val) {
        auto& p = storage[index];
        if(p.empty() || p[p.size()-1].first!=snap_id) {
            p.push_back({snap_id, val});
        }else{
            p[p.size()-1].second = val;
        }
    }
    
    int snap() {
        ++snap_id;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        auto& p = storage[index];
        int lo = 0;
        int hi = int(p.size())-1;
        while(lo<=hi){
            int mi = lo + (hi-lo)/2;
            if(p[mi].first==snap_id) return p[mi].second;
            else if(p[mi].first<snap_id){
                lo = mi + 1;
            }else{
                hi = mi - 1;
            }
        }
        if(hi < 0) return 0;
        else return p[hi].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
