class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        for(int i=0; i<S.size(); ++i){
            if(!s.empty() && s.top()==S[i]){
                s.pop(); 
            }else{
                s.push(S[i]);
            }
        }
        ostringstream oss;
        while(!s.empty()){
            oss<<s.top(); s.pop();
        }
        S = oss.str();
        reverse(S.begin(), S.end());
        return S;
    }
};
