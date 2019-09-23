use std::collections::VecDeque;

struct MovingAverage {
    size: usize,
    queue: VecDeque<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MovingAverage {

    /** Initialize your data structure here. */
    fn new(size: i32) -> Self {
        MovingAverage {
            size: size as usize,
            queue: VecDeque::new(),
        }
    }
    
    fn next(&mut self, val: i32) -> f64 {
        if self.queue.len() == self.size {
            self.queue.pop_front();
        }
        self.queue.push_back(val);
        
        let sum: i32 = self.queue.iter().sum();
        sum as f64/self.queue.len() as f64
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * let obj = MovingAverage::new(size);
 * let ret_1: f64 = obj.next(val);
 */
