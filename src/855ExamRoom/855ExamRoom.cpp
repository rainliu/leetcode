class ExamRoom {
    set<int> s;
    int N;
public:
    ExamRoom(int N) {
        this->N = N;
    }
    
    int seat() {
        int student = 0;
        if(s.size()>0){
            int distance = 0;
            for(auto it=s.begin(); it!=s.end(); ++it){
                if(it==s.begin()){
                    if(*it!=0 && *it>distance){
                        distance = *it;
                        student = 0;
                    }
                }
                
                if(it==prev(s.end())){
                    if(*it!=N-1&& (N-1-*it)>distance){                        
                        distance = (N-1-*it);
                        student = N-1;
                    }
                }else{
                    auto itt = next(it);
                    if((*itt-*it)/2 > distance){
                        distance = (*itt-*it)/2;
                        student = *it + distance;
                    }
                }
            }    
        }        
        s.insert(student);
        return student;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
