class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() > b.size() || (a.size()==b.size() && a < b);
        });
        unordered_set<string> s;
        for(const auto& word : words){
            s.insert(word);
        }
        for(const auto& word : words){
            bool check = true;
            for(int i=0; i<int(word.size())-1; ++i){
                string subword = word.substr(0, i+1);
                if(s.find(subword)==s.end()){
                    check = false;
                    break;
                }
            }
            if(check){
                return word;
            }
        }
        return "";
    }
};
