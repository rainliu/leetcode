impl Solution {
    pub fn convert_to_title(n: i32) -> String {
        let mut n = n;
        let mut result = String::new();
        while n-1 >= 0 {
            let m = ((n-1)%26) as u8;
            n = (n-1)/26;
            result.push((m + ('A' as u8)) as char);
        }    
        result.chars().rev().collect()
    }
}
