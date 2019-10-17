class Solution {
public:
    vector<int> diffWaysToCompute(string input) {        
        vector<int> result;        
        for(int k=0; k<input.size(); ++k){
            char ch = input[k];
            if(ch =='+'||ch=='-'||ch=='*'){
                auto left = diffWaysToCompute(input.substr(0,k));
                auto right= diffWaysToCompute(input.substr(k+1));
                for(int i=0; i<left.size();++i){
                    for(int j=0; j<right.size();++j){
                        int r;
                        switch(ch){
                            case '+': r = left[i]+right[j]; break;
                            case '-': r = left[i]-right[j]; break;
                            default:  r = left[i]*right[j]; break;
                        }
                        result.push_back(r);
                    }
                }
            }
        }
        if(result.empty()){
            result.push_back(stoi(input));
        }
        return result;
    }
};
