use std::collections::HashMap;
impl Solution {
    pub fn find_restaurant(list1: Vec<String>, list2: Vec<String>) -> Vec<String> {
        let mut map = HashMap::new();
        for j in 0..list2.len() {
            map.insert(&list2[j], j);
        }
        let mut global = list1.len()+list2.len();
        for i in 0..list1.len() {
            if let Some(x) = map.get(&list1[i]) {
                global = std::cmp::min(global, i+*x);
            }
        }
        let mut result = vec![];
        for i in 0..list1.len() {
            if let Some(x) = map.get(&list1[i]) {
                if i+*x == global {
                    result.push(list1[i].clone());
                }
            }
        }
        result
    }
}

impl Solution2 {
    pub fn find_restaurant(list1: Vec<String>, list2: Vec<String>) -> Vec<String> {
        let mut map = HashMap::new();
        for j in 0..list2.len() {
            map.insert(&list2[j], j);
        }
        let mut global = list1.len()+list2.len();
        let mut result = vec![];
        for i in 0..list1.len() {
            if let Some(x) = map.get(&list1[i]) {
                if i+*x <= global {
                    if i+*x < global {
                        result.clear();
                        global = i+*x;
                    }
                    result.push(list1[i].clone());
                }
            }
        }
        result
    }
}
