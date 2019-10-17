class Solution {
public:
    vector<int> diffWaysToCompute(string input) {        
        int n = input.size(); 
        if(n==0) return vector<int>{0};
        if(input.find("+")==string::npos&&
           input.find("-")==string::npos&&
           input.find("*")==string::npos){
            return vector<int>{stoi(input)};
        }
        
        vector<int> result;        
        for(int k=0; k<n; ++k){
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
        return result;
    }
};
