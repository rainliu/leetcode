class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> m(26, 0);
        for(int i=0; i<26; ++i){
            m[keyboard[i]-'a']=i;
        }
        int t = 0;
        int k = 0;
        for(int i=0; i<word.size(); ++i){
            int j = m[word[i]-'a'];
            t += abs(j-k);
            k = j;
        }
        return t;
    }
};
