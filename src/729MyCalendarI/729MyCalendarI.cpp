class MyCalendar {
    map<int,int> m;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = m.upper_bound(start);
        if(it!=m.end()){
            if(end > it->first) return false;
        }
        if(it!=m.begin()){
            it = prev(it);
            if(start < it->second) return false;
        }
        m.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
