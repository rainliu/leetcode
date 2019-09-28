use std::collections::{HashMap, HashSet};
struct ValidWordAbbr {
    abbrs: HashMap<String, HashSet<String>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl ValidWordAbbr {

    fn new(dictionary: Vec<String>) -> Self {
        let mut abbrs: HashMap<String, HashSet<String>> = HashMap::new();
        for word in dictionary {
            let b = word.as_bytes();
            let abbr = if b.len() > 2 {
                format!("{}{}{}", b[0], b.len()-2, b[b.len()-1])
            }else{
                word.clone()
            };
            if let Some(v) = abbrs.get_mut(&abbr) {
                v.insert(word);
            }else{
                let mut s = HashSet::new();
                s.insert(word);
                abbrs.insert(abbr, s);
            }
        }
        ValidWordAbbr{abbrs}
    }
    
    fn is_unique(&self, word: String) -> bool {
        let b = word.as_bytes();
        let abbr = if b.len() > 2 {
            format!("{}{}{}", b[0], b.len()-2, b[b.len()-1])
        }else{
            word.clone()
        };
        if let Some(v) = self.abbrs.get(&abbr) {
            if v.len() > 1 {
                false
            }else{
                v.contains(&word)
            }
        }else{
            true
        }
    }
}

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * let obj = ValidWordAbbr::new(dictionary);
 * let ret_1: bool = obj.is_unique(word);
 */
