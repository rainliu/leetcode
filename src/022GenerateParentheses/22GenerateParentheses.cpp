class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<string> a;
        backtracking(a, 0, n, result);
        return result;
    }
    
    void backtracking(vector<string>& a, int k, int n, vector<string>& result){
        if(is_solution(a, k, n)){
            process_solution(a, k, n, result);
        }else{
            auto cands = construct_candidates(a, k, n);
            k++;
            for(const auto& cand: cands){
                a.push_back(cand);
                backtracking(a, k, n, result);
                a.pop_back();
            }            
        }
    }
    
    bool is_solution(vector<string>& a, int k, int n){
        return k==n*2;
    }
    
    void process_solution(vector<string>& a, int k, int n, vector<string>& result){
        ostringstream oss;
        for(const auto& c: a){
            oss<<c;
        }
        result.push_back(oss.str());
    }
    
    vector<string> construct_candidates(vector<string>& a, int k, int n){
        int count[2]={0,0};
        for(const auto& p : a){
            if(p=="(") ++count[0];
            else ++count[1];
        }        
        if(count[0]==count[1]) return vector<string>{"("};
        else if(count[0]==n) return vector<string>{")"};
        else return vector<string>{"(", ")"};
    }
};  
