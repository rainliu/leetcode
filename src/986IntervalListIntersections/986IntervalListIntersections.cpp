class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> results;
        int i = 0;
        int j = 0;
        while(i<A.size()&&j<B.size()){
            int lo = max(A[i][0], B[j][0]);
            int hi = min(A[i][1], B[j][1]);
            if (lo<=hi){
                results.push_back(vector<int>{lo, hi});
            }
            if (A[i][1]<B[j][1]){
                ++i;
            }else{
                ++j;
            }
        }
        return results;
    }
};

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        map<int, int> ma;
        map<int, int> mb;
        for(int i = 0; i<A.size(); ++i){
            ma[A[i][0]] = 1;
            ma[A[i][1]] = -1;
        }
        for(int i = 0; i<B.size(); ++i){
            mb[B[i][0]] = 1;
            mb[B[i][1]] = -1;
        }
        
        vector<vector<int>> results;
        vector<int> result(2,0);
        
        auto p = ma.begin();
        auto q = mb.begin();
        int sum = 0;
        while(p!=ma.end() && q!=mb.end()) {
            if(p->first < q->first) {
                sum += p->second;
                if(sum==2){
                    result[0] = p->first;
                }else if(sum==1&&p->second==-1){
                    result[1] = p->first;
                    results.push_back(result);
                }
                ++p;
            }else if(p->first > q->first){
                sum += q->second;
                if(sum==2){
                    result[0] = q->first;
                }else if(sum==1&&q->second==-1){
                    result[1] = q->first;
                    results.push_back(result);
                }
                ++q;
            }else{
                sum += p->second + q->second;
                if(sum==2){
                    result[0] = p->first;
                }else if(sum==0){
                    result[1] = p->first;
                    results.push_back(result);
                }else{
                    results.push_back(vector<int>{p->first, p->first});
                }
                
                ++p;
                ++q;
            }      
        }        
        
        return results;
    }
};
