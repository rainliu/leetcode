class TopVotedCandidate {
    map<int, int> m;
    unordered_map<int,int> count;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int max_count = 0;
        int max_person = 0;
        for(int i=0; i<times.size(); ++i){
            int p = persons[i];
            int c = ++count[p];
            if(c>=max_count){
                max_person = p;
                m[times[i]] = p;
                max_count=c;
            }
        }   
    }
    
    int q(int t) {
        auto it = m.upper_bound(t);
        if(it==m.begin()){
            return -1;
        }else{
            return prev(it)->second;
        }
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
