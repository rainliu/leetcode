struct MinStack {
    stack:  std::cell::RefCell<Vec<i32>>,
    min_stack:  std::cell::RefCell<Vec<i32>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {

    /** initialize your data structure here. */
    fn new() -> Self {
        MinStack{
            stack:  std::cell::RefCell::new(vec![]),
            min_stack:  std::cell::RefCell::new(vec![]),
        }
    }
    
    fn push(&self, x: i32) {
        let mut ms = self.min_stack.borrow_mut();
        if ms.is_empty() || (!ms.is_empty() && x <= ms[ms.len()-1]) {
            ms.push(x);
        }
        self.stack.borrow_mut().push(x);
    }
    
    fn pop(&self) {
        if let Some(x) = self.stack.borrow_mut().pop() {
            let mut ms = self.min_stack.borrow_mut();
            if let Some(&y) = ms.last() {
                if x == y {
                    ms.pop();
                }
            };
        }
    }
    
    fn top(&self) -> i32 {
        if let Some(&x) = self.stack.borrow().last() {
            x
        }else{
            0
        }
    }
    
    fn get_min(&self) -> i32 {
        if let Some(&x) = self.min_stack.borrow().last() {
            x
        }else{
            0
        }
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack::new();
 * obj.push(x);
 * obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: i32 = obj.get_min();
 */
