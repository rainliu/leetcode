class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return dfs(s, i, s.size(), 1);
    }
    
    string dfs(string& s, int& i, int n, int repeat_times) {
        ostringstream oss;
        int k = 0;
        while (i < n && s[i] != ']') {
            if (s[i]>='0'&&s[i]<='9'){
                k = k*10+s[i]-'0';
                ++i;
            }else if(s[i]=='['){
                ++i;
                oss<<dfs(s, i, n, k);
                k=0;
            }else{
                oss<<s[i];
                k=0;
                ++i;
            }
        }    
        ++i; // eat ']'
        
        ostringstream repeated_oss;
        for (int j=0; j<repeat_times; ++j){
            repeated_oss<<oss.str();
        }
        return repeated_oss.str();
    }
};
