class Solution {
public:
    string findLongestWord2(string s, vector<string>& d) {
        string global = ""; 
        for (const auto& a: d) {
            if (containWord(s, a) && 
                (a.size()>global.size() || 
                 (a.size()==global.size() && a < global))
               ) {
                global = a;
            }
        }
        return global;
    }
    
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](const string& a, const string& b) {
            return a.size() > b.size() || (a.size() == b.size() && a < b);    
        });    
        for (const auto& a: d) {
            if (containWord(s, a)) {
                return a;
            }
        }
        return "";
    }
    
    bool containWord(const string& s, const string& a) {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < a.size()) {
            if(s[i]==a[j]){
                ++i;
                ++j;
            }else{
                ++i;
            }
        }
        return j==a.size();
    }
};
