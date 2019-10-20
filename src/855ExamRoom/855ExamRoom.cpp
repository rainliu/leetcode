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
            auto cur = s.begin();
            auto pre = s.end();
            int dist = *cur;
            while(cur!=s.end()){
                if(pre!=s.end()){
                    if((*cur-*pre)/2 > dist){
                        dist = (*cur-*pre)/2;
                        student = *pre + dist;
                    }
                }
                pre = cur;
                ++cur;
            }    
            if(N-1-*pre>dist){                        
                student = N-1;
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
            auto cur = s.begin();
            auto pre = s.end();
            int distance = *cur;
            while(cur!=s.end()){
                if(pre!=s.end()){
                    if((*cur-*pre)/2 > distance){
                        distance = (*cur-*pre)/2;
                        student = *pre + distance;
                    }
                }
                pre = cur;
                ++cur;
            }    
            if(*pre!=N-1&& (N-1-*pre)>distance){                        
                distance = (N-1-*pre);
                student = N-1;
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
