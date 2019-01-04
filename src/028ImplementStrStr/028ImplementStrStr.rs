impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        let n1 = haystack.len();
        let n2 = needle.len();
        let h = haystack.as_bytes();
        let n = needle.as_bytes();
        for i in 0..(n1-n2+1) as i32 {
            let mut j:usize = 0;
            while j < n2 {
                if h[(i as usize)+j] != n[j] {
                    break;
                }    
                j += 1;
            }  
            if j == n2 {
                return i;
            }
        }
        -1
    }
}
