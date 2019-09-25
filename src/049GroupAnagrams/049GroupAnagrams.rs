use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut map:HashMap<Vec<u8>, Vec<String>> = HashMap::new();        
        
        for str in strs{
            let mut b = str.as_bytes().to_vec();
            b.sort();
            if let Some(x) = map.get_mut(&b) {
                x.push(str);
            }else{
                map.insert(b, vec![str]);
            }
        }
        
        map.values().cloned().collect()
    }
}
