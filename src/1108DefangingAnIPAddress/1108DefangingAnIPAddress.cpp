class Solution {
public:
    string defangIPaddr(string address) {
        ostringstream oss;
        for(auto ch: address) {
            if(ch != '.'){
                oss<<ch;
            }else{
                oss<<"[.]";
            }
        }
        return oss.str();
    }
};
