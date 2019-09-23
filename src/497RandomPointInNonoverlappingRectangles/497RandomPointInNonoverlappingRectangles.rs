use rand::{thread_rng, Rng};
use std::collections::BTreeMap;

struct Solution {
    sum: i32,
    map: BTreeMap<i32, usize>,
    rects: Vec<Vec<i32>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {

    fn new(rects: Vec<Vec<i32>>) -> Self {
        let mut map = BTreeMap::new();
        let mut sum = 0;
        for i in 0..rects.len() {
            sum += (rects[i][2]-rects[i][0]+1)*(rects[i][3]-rects[i][1]+1);
            map.insert(sum, i);
        }
        Solution{
            sum,
            map,
            rects,
        }
    }
    
    fn pick(&self) -> Vec<i32> {
        let mut rng = thread_rng();
        let r: i32 = rng.gen_range(0, self.sum+1);
        let mut ceiling_key = 0;
        for key in self.map.keys() {
            if *key >= r {
                ceiling_key = *key;
                break;
            }
        }
        if let Some(index) = self.map.get(&ceiling_key) {
            let rect = &self.rects[*index];
            let x = rng.gen_range(rect[0], rect[2]+1);
            let y = rng.gen_range(rect[1], rect[3]+1);
            vec![x, y]
        }else{
            vec![]
        }
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(rects);
 * let ret_1: Vec<i32> = obj.pick();
 */
