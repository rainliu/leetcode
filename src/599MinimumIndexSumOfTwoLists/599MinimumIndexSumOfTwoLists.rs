use std::collections::HashMap;
impl Solution {
    pub fn find_restaurant(list1: Vec<String>, list2: Vec<String>) -> Vec<String> {
        let mut map1 = HashMap::new();
        let mut map2 = HashMap::new();
        for i in 0..list1.len() {
            map1.insert(&list1[i], i);
        }
        for j in 0..list2.len() {
            map2.insert(&list2[j], j);
        }
        let mut global = list1.len()+list2.len();
        for (key, val) in map1.iter() {
            if let Some(x) = map2.get(key) {
                global = std::cmp::min(global, *val+*x);
            }
        }
        let mut result = vec![];
        for (key, val) in map1.iter() {
            if let Some(x) = map2.get(key) {
                if *val+*x == global {
                    result.push((*key).clone());
                }
            }
        }
        result
    }
}
