use std::collections::HashMap;
struct Logger {
    timestamp: HashMap<String, i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Logger {

    /** Initialize your data structure here. */
    fn new() -> Self {
        Logger{
            timestamp: HashMap::new(),
        }
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    fn should_print_message(&mut self, timestamp: i32, message: String) -> bool {
        if let Some(x) = self.timestamp.get_mut(&message) {
            if *x+10 > timestamp {
                return false;
            }else{
                *x = timestamp;
                return true;
            }
        }else{
            self.timestamp.insert(message, timestamp);
            return true;
        }
    }
}

/**
 * Your Logger object will be instantiated and called as such:
 * let obj = Logger::new();
 * let ret_1: bool = obj.should_print_message(timestamp, message);
 */
