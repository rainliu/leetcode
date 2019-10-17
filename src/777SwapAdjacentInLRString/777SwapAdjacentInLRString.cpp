class Solution {
public:
    bool canTransform(string start, string end) {
        int i=0;
        int j=0;
        while(i<start.size()&&start[i]=='X') ++i;
        while(j<end.size()&&end[j]=='X') ++j;
        while(i<start.size()&&j<end.size()){
            if(start[i]!=end[j]){
                return false;
            }else if(start[i]=='R'){
                if(i>j) return false;
            }else{
                if(i<j) return false;
            }
            ++i;
            ++j;
            while(i<start.size()&&start[i]=='X') ++i;
            while(j<end.size()&&end[j]=='X') ++j;
        }
        if(i!=start.size()||j!=end.size()) return false;
        
        return true;
    }
};
