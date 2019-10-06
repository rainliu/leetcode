class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int count = 0;
        for (const string& word: words) {
            count += isExpressiveWord(S, word);
        }
        return count;
    }
    bool isExpressiveWord(const string& S, const string& word) {
        int i = 0;
        int j = 0;
        int c = 0;
        while (i<S.size()&&j<word.size()) {
            if(S[i]!=word[j]) {
                return false;
            }else{
                c = 1;
                while(i+1<S.size()&&j+1<word.size()&&
                      S[i+1]==S[i]&&word[j+1]==word[j]) {
                    ++i; ++j; ++c;
                }
                if(i+1<S.size()&&S[i+1]==S[i]){
                    while(i+1<S.size()&&S[i+1]==S[i]){
                        ++i; ++c;
                    }
                    if(c<3){
                        return false;
                    }
                }
            }
            ++i; ++j;
        }
        return i==S.size() && j==word.size();
    }
};
