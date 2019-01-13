use std::collections::HashMap;
impl Solution {
    pub fn uncommon_from_sentences(a: String, b: String) -> Vec<String> {
        let mut iter_a = a.split_whitespace();
        let mut iter_b = b.split_whitespace();
        let mut map_a = HashMap::new();
        let mut map_b = HashMap::new();
        while let Some(s) = iter_a.next() {
            if let Some(x) = map_a.get_mut(s) {
                *x += 1;
            }else{
                map_a.insert(s, 1);
            }
        }
        while let Some(s) = iter_b.next() {
            if let Some(x) = map_b.get_mut(s) {
                *x += 1;
            }else{
                map_b.insert(s, 1);
            }
        }
        let mut result = vec![];
        for (key, val) in map_a.iter() {
            if *val == 1 && !map_b.contains_key(key) {
                result.push(String::from(*key));    
            }
        }
        for (key, val) in map_b.iter() {
            if *val == 1 && !map_a.contains_key(key) {
                result.push(String::from(*key));    
            }
        }
        result
    }
}

impl Solution2 {
    pub fn uncommon_from_sentences(a: String, b: String) -> Vec<String> {
        let mut iter_a = a.split_whitespace();
        let mut iter_b = b.split_whitespace();
        let mut map = HashMap::new();
        while let Some(s) = iter_a.next() {
            if let Some(x) = map.get_mut(s) {
                *x += 1;
            }else{
                map.insert(s, 1);
            }
        }
        while let Some(s) = iter_b.next() {
            if let Some(x) = map.get_mut(s) {
                *x += 1;
            }else{
                map.insert(s, 1);
            }
        }
        let mut result = vec![];
        for (key, val) in map.iter() {
            if *val == 1 {
                result.push(String::from(*key));
            }
        }
        result
    }
}
