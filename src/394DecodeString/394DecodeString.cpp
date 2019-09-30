class Solution2 {
public:
    string decodeString(string s) {
        int i = 0;
        return dfs(s, i);
    }
    
    string dfs(string& s, int& i) {
        string result;
        while (i < s.size() && s[i] != ']') {
            if (!(s[i]>='0'&&s[i]<='9')){
                result += s[i++];
            }else{
                int k = 0;
                while (s[i]>='0'&&s[i]<='9'){
                    k = k*10+s[i++]-'0';
                }
                
                ++i; // eat '['
                string t = dfs(s, i);
                ++i; // eat ']'
                while (k-->0) {
                    result += t;
                }
            }
        }   
        
        return result;
    }
};

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
