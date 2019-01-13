use std::collections::HashMap;
impl Solution {
    pub fn word_pattern(pattern: String, str: String) -> bool {
        let mut words = str.split_whitespace();
        let mut chars = pattern.chars();
        let mut c2w = HashMap::new();
        let mut w2c = HashMap::new();
        loop {
            match (chars.next(), words.next()) {
                (Some(c), Some(w)) => {
                    if !c2w.contains_key(&c) && !w2c.contains_key(&w) {
                        c2w.insert(c, w);
                        w2c.insert(w, c);
                    }else if c2w.contains_key(&c) && w2c.contains_key(&w) {
                        let w1 = c2w.get(&c).unwrap();
                        let c1 = w2c.get(&w).unwrap();
                        if *c1 != c || *w1 != w {
                            return false;
                        }
                    }else{
                        return false;
                    }
                }
                (None, None) => return true,
                _ => return false,
            };
        }
        true
    }
}
