use std::collections::HashMap;
impl Solution {
    pub fn shortest_completing_word(license_plate: String, words: Vec<String>) -> String {
        let mut lp_map = HashMap::new();
        for c in license_plate.into_bytes() {
            if (c>='a' as u8&&c<='z' as u8) || (c>='A' as u8&&c<='Z' as u8){
                let key = if c>='a' as u8&&c<='z' as u8 {c-'a' as u8} else {c-'A' as u8};
                if let Some(x) = lp_map.get_mut(&key) {
                    *x += 1;
                }else{
                    lp_map.insert(key, 1);
                }
            }
        }
        let mut smallest_length = std::usize::MAX;
        let mut smallest_word = "".to_string();
        for word in words {
            let mut lp_copy = lp_map.clone();
            for c in word.as_bytes() {
                let key = c-'a' as u8;
                if let Some(x) = lp_copy.get_mut(&key) {
                    *x -= 1;
                    if *x == 0 {
                        lp_copy.remove(&key);
                    }
                }
            }    
            if lp_copy.len()==0 && word.len() < smallest_length{
                smallest_length = word.len();
                smallest_word = word;
            }
        }
        smallest_word
    }
}
