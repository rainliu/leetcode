impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        //assert!(s.len()==t.len());
        let mut map1: std::collections::HashMap<char, char> = std::collections::HashMap::new();
        let mut map2: std::collections::HashMap<char, char> = std::collections::HashMap::new();
        let (mut is, mut it) = (s.chars(), t.chars());
        while let (Some(cs), Some(ct)) = (is.next(), it.next()) {
            match (map1.get(&cs), map2.get(&ct)){
                (Some(&mt), Some(&ms)) => {
                    if mt!=ct || ms!=cs {
                        return false;
                    }
                }
                (None, None) => {
                    map1.insert(cs, ct);
                    map2.insert(ct, cs);
                }
                _ => return false,
            };
        }
        true
    }
}
