use std::collections::{HashMap,BinaryHeap};
impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut map:HashMap<i32, i32> = HashMap::new();
        for num in nums {
            let counter = map.entry(num).or_insert(0);
            *counter+=1;
        }
        
        let mut heap:BinaryHeap<(i32, i32)> = BinaryHeap::new();
        for (key, val) in map.iter() {
            let top = if heap.len() as i32 >= k {
                heap.peek()
            }else{
                None
            };
            if let Some(v) = top {
                if -v.0 < *val {
                    heap.pop();
                    heap.push((-*val, *key));
                }
            }else{
                heap.push((-*val, *key));
            }
        }
        
        let mut result = vec![];
        
        for (_val, key) in heap.iter().rev() {
            result.push(*key);
        }
        
        result
    }
}
