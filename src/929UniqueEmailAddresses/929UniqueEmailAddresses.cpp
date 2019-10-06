class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;  
        for(const string& email: emails) {
            s.insert(uniqueEmail(email));
        }
        return s.size();
    }
    
    string uniqueEmail(const string& email) {
        auto n = email.find("@");
        auto local_name = email.substr(0, n);
        auto plus = local_name.find("+");
        if (plus != string::npos) {
            local_name = local_name.substr(0, plus);
        }
        ostringstream oss;
        for (auto ch: local_name) {
            if (ch != '.') oss<<ch;
        }
        oss<<email.substr(n);
        return oss.str();
    }
};
