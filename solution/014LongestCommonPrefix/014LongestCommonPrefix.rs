impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        if strs.is_empty() {
            return "".to_string();
        }
        let n = strs[0].len();
        let n = strs.iter().fold(n, |acc, s| if s.len() < acc { s.len() } else {acc});
        for i in 0..n {
            let b = strs[0].as_bytes()[i];
            for j in 1..strs.len() {
                if strs[j].as_bytes()[i] != b {
                    return strs[0].chars().take(i).collect();
                }
            }
        }
        strs[0].chars().take(n).collect()
    }
}
