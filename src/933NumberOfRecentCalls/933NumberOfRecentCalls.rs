use std::cell::RefCell;
use std::collections::VecDeque;

struct RecentCounter {
    queue: RefCell<VecDeque<i32>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RecentCounter {

    fn new() -> Self {
        RecentCounter{queue: RefCell::new(VecDeque::new())}
    }
    
    fn ping(&self, t: i32) -> i32 {
        let mut q = self.queue.borrow_mut();
        while let Some(s) = q.front() {
            if *s < t-3000 {
                q.pop_front();
            }else{
                break;
            }
        }
        q.push_back(t);
        q.len() as i32
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * let obj = RecentCounter::new();
 * let ret_1: i32 = obj.ping(t);
 */
