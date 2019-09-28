class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        ostringstream oss;
        oss<<strs.size()<<"#";
        for (auto str : strs) {
            oss<<str.size()<<"#"<<str;    
        }
        return oss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        int j = 0;
        while (j < s.size() && s[j]!='#') ++j;
        assert(j<s.size());
        int array_size = stoi(s.substr(i,j-i));
        for (int k = 0; k < array_size; ++k){
            ++j;
            i = j;
            while (j < s.size() && s[j]!='#') ++j;
            assert(j<s.size());
            int str_size = stoi(s.substr(i,j-i));
            strs.push_back(s.substr(j+1, str_size));
            j += str_size;
        }
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
