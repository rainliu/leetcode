class Solution {
public:
    string reorganizeString(string S) {
        vector<int> count(26, 0);
        for (auto& c: S){
            ++count[c-'a'];
        }
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<26; ++i){
            if(count[i]>0) pq.push({count[i], i});
        }
        ostringstream oss;
        while(pq.size()>=2) {
            auto p = pq.top(); pq.pop(); --p.first;
            auto q = pq.top(); pq.pop(); --q.first;
            oss<<(char)('a'+p.second);
            oss<<(char)('a'+q.second);
            if (p.first>0) pq.push(p);
            if (q.first>0) pq.push(q);
        }
        
        if(pq.size()==1){
            auto p = pq.top();
            oss<<(char)('a'+p.second);
            if (p.first==1) {
                return oss.str();
            }else{
                return "";
            }
        }else{
            return oss.str();
        }
    }
};
