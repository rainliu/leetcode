class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<int> outdegree(n+1, 0);
        unordered_map<int, unordered_set<int>> m;
        
        bool empty = true;
        int count = 0;
        for(const auto& seq : seqs){
            for(int i=0; i<seq.size(); ++i){
                if(seq[i]<=0 || seq[i]>n) return false;
                if(i>0&&m[seq[i]].find(seq[i-1])==m[seq[i]].end()){
                    m[seq[i]].insert(seq[i-1]);
                    if(outdegree[seq[i-1]]++==0) ++count;
                }
                empty = false;
            }
        }
        if(empty || count != n-1) return false;
        for(int i=n-1; i>=0; --i){
            if(outdegree[org[i]]>0) return false;
            for(const auto& num : m[org[i]]){
                if(--outdegree[num]==0 && i>0 && num!=org[i-1]){
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size(), count=0;
        vector<int> degreeout(n+1);
        unordered_map<int,unordered_set<int>> m;
        bool empty = true;
        for(const auto &seq : seqs){
            for(int i=seq.size()-1; i>=0; --i){
                if(seq[i]<=0 || seq[i]>n) return false;
                if(i>0 && m[seq[i]].find(seq[i-1])==m[seq[i]].end()){
                    m[seq[i]].insert(seq[i-1]);
                    if(degreeout[seq[i-1]]++==0) count++;
                }
                empty=false;
            }
        }
        if(empty || count!=n-1) return false;
        for(int i=n-1; i>=0; --i){
            if(degreeout[org[i]]>0) return false;
            for(const auto &p : m[org[i]]){
                if(--degreeout[p]==0 && p!=org[i-1]){
                    return false;
                }
            }
        }
        return true;
    }
};
